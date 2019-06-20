/*
    DataTypeClass: DoubleComplexNumberType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_DoubleComplexNumberType_h__
#define __OpcUaStackCore_DoubleComplexNumberType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT DoubleComplexNumberType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<DoubleComplexNumberType> SPtr;
        typedef std::vector<DoubleComplexNumberType::SPtr> Vec;
    
        DoubleComplexNumberType(void);
        DoubleComplexNumberType(const DoubleComplexNumberType& value);
        virtual ~DoubleComplexNumberType(void);
        
        OpcUaDouble& real(void);
        OpcUaDouble& imaginary(void);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void);
        virtual std::string namespaceName(void);
        virtual std::string typeName(void);
        virtual OpcUaNodeId typeId(void);
        virtual OpcUaNodeId binaryTypeId(void);
        virtual OpcUaNodeId xmlTypeId(void);
        virtual OpcUaNodeId jsonTypeId(void);
        virtual void opcUaBinaryEncode(std::ostream& os) const;
        virtual void opcUaBinaryDecode(std::istream& is);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool jsonEncode(boost::property_tree::ptree& pt, const std::string& element);
        virtual bool jsonEncode(boost::property_tree::ptree& pt);
        virtual bool jsonDecode(boost::property_tree::ptree& pt, const std::string& element);
        virtual bool jsonDecode(boost::property_tree::ptree& pt);
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        void copyTo(DoubleComplexNumberType& value);
        bool operator==(const DoubleComplexNumberType& value);
        bool operator!=(const DoubleComplexNumberType& value);
        DoubleComplexNumberType& operator=(const DoubleComplexNumberType& value);
    
      private:
        OpcUaDouble real_;
        OpcUaDouble imaginary_;
    
    };
    
    class DLLEXPORT DoubleComplexNumberTypeArray
    : public OpcUaArray<DoubleComplexNumberType::SPtr, SPtrTypeCoder<DoubleComplexNumberType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<DoubleComplexNumberTypeArray> SPtr;
    };

}

#endif