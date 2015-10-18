/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackCore/StandardDataTypes/BuildInfo.h"

namespace OpcUaStackCore
{

	BuildInfo::BuildInfo(void)
	: productUri_()
	, manufacturerName_()
	, productName_()
	, softwareVersion_()
	, buildNumber_()
	, buildDate_()
	{
	}

	BuildInfo::~BuildInfo(void)
	{
	}

	OpcUaString&
	BuildInfo::productUri(void)
	{
		return productUri_;
	}

	OpcUaString&
	BuildInfo::manufacturerName(void)
	{
		return manufacturerName_;
	}

	OpcUaString&
	BuildInfo::productName(void)
	{
		return productName_;
	}

	OpcUaString&
	BuildInfo::softwareVersion(void)
	{
		return softwareVersion_;
	}

	OpcUaString&
	BuildInfo::buildNumber(void)
	{
		return buildNumber_;
	}

	OpcUaDateTime&
	BuildInfo::buildDate(void)
	{
		return buildDate_;
	}

}

