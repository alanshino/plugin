#include "gcc-plugin.h"
#include "plugin-version.h"

int plugin_is_GPL_compatible;

int plugin_init(struct plugin_name_args *plugin_info, struct plugin_gcc_version *version)
{
    if (!plugin_default_version_check(version, &gcc_version)) 
    {
	printf("This GCC plugin is for version %d.%d\n", GCCPLUGIN_VERSION_MAJOR, GCCPLUGIN_VERSION_MINOR);
	return 1;
    }
    
    printf("Plugin info\n=============\n\nBase name: %s\nFull name: %s\nNumber of arguments of this plugin: %d\n", plugin_info->base_name, plugin_info->full_name, plugin_info->argc);
    /*
    for (int i = 0; i < plugin_info->argc; i++) {
	   // printf("Argument %d: Key: ");
      std::cerr << "Argument " << i << ": Key: " << plugin_info->argv[i].
	key << ". Value: " << plugin_info->argv[i].value << "\n";

    }
    */

    if (plugin_info->version != NULL) {
	printf("Version string of the plugin: %s\n", plugin_info->version);
    }
    
    if (plugin_info->version != NULL) {
        printf("Help string of the plugin: %s\n", plugin_info->version);
    }
    
    printf("\nVersion information\n=============\n\nBase version: %s\nData stamp: %s\nDev phase: %s\nRevision: %s\nConfiguration arguments: %s\n",\
		    version->basever, version->datestamp, version->devphase, version->devphase, version->configuration_arguments);

    printf("Gcc Plugin successfully initialized\n");
    return 0;
} 
