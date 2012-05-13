#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H
#ifndef COREDLL
#error You are not supposed to include this H file, EVER.
#endif

namespace Mavgine2
{
	class PluginManager
	{
		public:
			static PluginManager* GetSingleton();

		private:
			PluginManager();
			~PluginManager();


	};
};

#endif