#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "HarvestPlugin.h"

void HarvestPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
   }
}

void HarvestPlugin::run() {
   
}

void HarvestPlugin::output(std::string file) {
	std::string command;
   command = "harvesttools";
   if (parameters.count("inputGingr") != 0)
	   command += " -i "+std::string(PluginManager::prefix())+"/"+parameters["inputGingr"];
   if (parameters.count("inputFASTA") != 0)
	   command += " -f "+std::string(PluginManager::prefix())+"/"+parameters["inputFASTA"];
   if (parameters.count("inputMAF") != 0)
	   command += " -a "+std::string(PluginManager::prefix())+"/"+parameters["inputMAF"];
   if (parameters.count("inputMultiFASTA") != 0)
	   command += " -m "+std::string(PluginManager::prefix())+"/"+parameters["inputMultiFASTA"];
   if (parameters.count("inputNewick") != 0)
	   command += " -n "+std::string(PluginManager::prefix())+"/"+parameters["inputNewick"];
   if (parameters.count("inputVCF") != 0)
	   command += " -v "+std::string(PluginManager::prefix())+"/"+parameters["inputVCF"];
   if (parameters.count("inputXMFA") != 0)
	   command += " -x "+std::string(PluginManager::prefix())+"/"+parameters["inputXMFA"];
   if (parameters.count("outputGingr") != 0)
	   command += " -o "+std::string(PluginManager::prefix())+"/"+parameters["outputGingr"];
   if (parameters.count("outputFASTA") != 0)
	   command += " -F "+std::string(PluginManager::prefix())+"/"+parameters["outputFASTA"];
   if (parameters.count("outputSNP") != 0)
	   command += " -S "+std::string(PluginManager::prefix())+"/"+parameters["outputSNP"];
   if (parameters.count("outputMultiFASTA") != 0)
	   command += " -M "+std::string(PluginManager::prefix())+"/"+parameters["outputMultiFASTA"];
   if (parameters.count("outputNewick") != 0)
	   command += " -N "+std::string(PluginManager::prefix())+"/"+parameters["outputNewick"];
   if (parameters.count("outputVCF") != 0)
	   command += " -V "+std::string(PluginManager::prefix())+"/"+parameters["outputVCF"];
   if (parameters.count("outputXMFA") != 0)
	   command += " -X "+std::string(PluginManager::prefix())+"/"+parameters["outputXMFA"];
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<HarvestPlugin> HarvestPluginProxy = PluginProxy<HarvestPlugin>("Harvest", PluginManager::getInstance());
