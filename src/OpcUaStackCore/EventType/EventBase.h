/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_EventBase_h__
#define __OpcUaStackCore_EventBase_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{

	class DLLEXPORT EventBase
	{
	  public:
		typedef boost::shared_ptr<EventBase> SPtr;

		typedef enum
		{
			Success,
			BadEventTypeNotExist,
			BadBrowseNameListEmpty,
			BadBrowseNameNotExist,
			BadValueNotExist,
		} ResultCode;

		EventBase(void);
		virtual ~EventBase(void);

		void namespaceArray(std::vector<std::string>* namespaceArray);
		int32_t findNamespaceIndex(const std::string& namespaceUri);

		ResultCode get(
			OpcUaNodeId& eventType,
			std::list<OpcUaQualifiedName::SPtr>& browseNameList,
			OpcUaVariant::SPtr& variant
		);

		virtual void mapNamespaceUri(void);

		//
		// The get call succeeds under the following conditions
		//
		virtual OpcUaVariant::SPtr get(
			OpcUaNodeId& eventType,
			bool& eventTypeFound,			// The pass value must be true
			std::list<OpcUaQualifiedName::SPtr>& browseNameList,
			ResultCode& resultCode
		);

	  private:
		std::vector<std::string>* namespaceArray_;
	};


}

#endif
