#ifndef ENGINE_H
#define ENGINE_H

#include <string>

namespace Mavgine2
{
	class Engine
	{
		public:
			virtual void Initialize(std::string strGameName);
	};
};

#endif