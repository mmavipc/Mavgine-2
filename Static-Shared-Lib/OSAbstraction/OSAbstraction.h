#ifndef OSABSTRACTION_H
#define OSABSTRACTION_H

#include <string>

namespace Mavgine2
{
	enum MsgBoxType
	{
		NORMAL = 0,
		ALERT,
		ERRORMSG
	};

	class OSInterface
	{
		public:
			virtual void MsgBox(const std::string &strTitle, const std::string &strText, const MsgBoxType &msgType) = 0;
			virtual void* LoadLibAndGetFunc(std::string strLibName, const char* szFuncName) = 0;
	};

	OSInterface* GetOSI();

	class WinInterface : public OSInterface
	{
		public:
			virtual void MsgBox(const std::string &strTitle, const std::string &strText, const MsgBoxType &msgType);
			virtual void* LoadLibAndGetFunc(std::string strLibName, const char* szFuncName);
		
		private:
			friend Mavgine2::OSInterface* Mavgine2::GetOSI();
			WinInterface();
			~WinInterface();
	};
}
#endif