#include "unittest.h"
#include "FilterOperatorHelpers.h"

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/LiteralOperand.h"
#include "OpcUaStackCore/ServiceSet/ElementOperand.h"
#include "OpcUaStackCore/Filter/FilterStack.h"


using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(FilterStack_)

BOOST_AUTO_TEST_CASE(FilterStack_)
{
	std::cout << "FilterStack_" << std::endl;
}

BOOST_AUTO_TEST_CASE(FilterStack_returns_True_if_empty)
{
    FilterStack stack;

    bool filterResult;
    BOOST_REQUIRE(stack.process(filterResult));
    BOOST_REQUIRE(filterResult == true);
}

BOOST_AUTO_TEST_CASE(FilterStack_FilterOperatorUnsupported)
{
    FilterStack stack;

    ContentFilterElement::SPtr eqElement = makeOperatorWith2LitteralOperands<OpcUaUInt32,OpcUaUInt32>(
               BasicFilterOperator::BasicFilterOperator_IsNull, 100, 120);

    ContentFilter filter;
    filter.elements()->push_back(eqElement);

    ContentFilterResult result;
    stack.receive(filter, result);

    ContentFilterElementResult::SPtr elementResult;
    result.elementResults()->get(0, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::BadFilterOperatorUnsupported);
}

BOOST_AUTO_TEST_CASE(FilterStack_BadFilterOperatorInvalid)
{
    FilterStack stack;
    const int INVALID_OPERATOR_ID = 1000;

    ContentFilterElement::SPtr eqElement = makeOperatorWith2LitteralOperands<OpcUaUInt32,OpcUaUInt32>(
               (BasicFilterOperator)INVALID_OPERATOR_ID, 100, 120);

    ContentFilter filter;
    filter.elements()->push_back(eqElement);

    ContentFilterResult result;
    stack.receive(filter, result);

    ContentFilterElementResult::SPtr elementResult;
    result.elementResults()->get(0, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::BadFilterOperatorInvalid);
}

BOOST_AUTO_TEST_CASE(FilterStack_2_level_tree)
{
    // (10 == 10) == (20 == 20) => true
    FilterStack stack;

    ContentFilterElement::SPtr eqElement1 = makeOperatorWith2ElementOperands(
            BasicFilterOperator::BasicFilterOperator_Equals, 1, 2);

    ContentFilterElement::SPtr eqElement2 = makeOperatorWith2LitteralOperands<OpcUaUInt32,OpcUaUInt32>(
            BasicFilterOperator::BasicFilterOperator_Equals, 10, 10);

    ContentFilterElement::SPtr eqElement3 = makeOperatorWith2LitteralOperands<OpcUaUInt32,OpcUaUInt32>(
            BasicFilterOperator::BasicFilterOperator_Equals, 20, 20);

    ContentFilter filter;
    filter.elements()->resize(3);
    filter.elements()->push_back(eqElement1);
    filter.elements()->push_back(eqElement2);
    filter.elements()->push_back(eqElement3);

    ContentFilterResult result;

    BOOST_REQUIRE(stack.receive(filter, result) == OpcUaStatusCode::Success);

    ContentFilterElementResult::SPtr elementResult;

    result.elementResults()->get(0, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::Success);
    result.elementResults()->get(1, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::Success);
    result.elementResults()->get(2, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::Success);

    bool filterResult;
    BOOST_REQUIRE(stack.process(filterResult));
    BOOST_REQUIRE(filterResult == true);
}

BOOST_AUTO_TEST_CASE(FilterStack_2_level_half_tree)
{
    // 10  == (20 == 30) => false
    FilterStack stack;

    ContentFilterElement::SPtr eqElement1 = makeOperatorWithElementAndLiteralOperands<OpcUaUInt32>(
            BasicFilterOperator::BasicFilterOperator_Equals, 1, 10);

    ContentFilterElement::SPtr eqElement2 = makeOperatorWith2LitteralOperands<OpcUaUInt32,OpcUaUInt32>(
            BasicFilterOperator::BasicFilterOperator_Equals, 20, 30);

    ContentFilter filter;
    filter.elements()->resize(2);
    filter.elements()->push_back(eqElement1);
    filter.elements()->push_back(eqElement2);


    ContentFilterResult result;

    BOOST_REQUIRE(stack.receive(filter, result) == OpcUaStatusCode::Success);

    ContentFilterElementResult::SPtr elementResult;

    result.elementResults()->get(0, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::Success);
    result.elementResults()->get(1, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::Success);

    bool filterResult;
    BOOST_REQUIRE(stack.process(filterResult));
    BOOST_REQUIRE(filterResult == false);
}


BOOST_AUTO_TEST_SUITE_END()
