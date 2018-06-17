#include "scene.h"
#include <iostream>
#include <algorithm>
#include "fileutils.h"
#include "defs.h"
#include <fstream>
#include <objects.h>
Scene::Scene(){}
Scene::Scene(const std::string file)
{
    loadScene(file);
}
inline bool clean(std::string &s)
{
s = s.substr(0,s.find_first_of('#'));//take only the part before "#"
if(isSpaces(s) || s.empty())//Compare against spaces
    return true;
else
    return false;
}
inline void trimspaces(std::string &s)
{

    s = s.substr(s.find_first_not_of(' '));
    s = s.substr(0,s.find_last_not_of(' ')+1);
}

void Scene::loadScene(const std::string file)
{
    //opening info file
    std::ifstream ifs(file);
    if(!ifs.is_open())
    {   DOUT << "Could not open file : "<<file<<std::endl;
        return ;}

    std::string directory;
//we have the file now we need the scene directory
    while(std::getline(ifs,directory))
    {
        if(clean(directory))
            continue;

        //we got our directory now we need to add the absolute path
        //the +1 means we keep the slash
        directory = AddFilePath(file.substr(0,file.find_last_of('/')+1).c_str(),directory.c_str());
        DOUT << "Directory : " << directory << std::endl;
        //then we can break the loop and look for the scene parameters
        break;
    }

    std::string location;
    std::string objLocation="";
    std::string mtlLocation="";
    while(std::getline(ifs,location))
    {
        if(clean(location)) continue;

        if(location[0]=='o')//objPath
        {
            if(location=="o:." || location=="m:. ")
                objLocation="";
            else
                objLocation=location.substr(2);
            //remove spaces
            trimspaces(objLocation);

            //add the first '/' if there is none
            if(objLocation[0]!='/')
                objLocation="/"+objLocation;
            DOUT << "objLocation : " << objLocation << std::endl;
            continue;
        }
        if(location[0]=='m')
        {
            if(location=="m:." || location=="m:. ")
                mtlLocation="";
            else
                mtlLocation=location.substr(2);
            //remove spaces
            trimspaces(mtlLocation);
            //add the first '/' if there is none

            if(mtlLocation[0]!='/')
                mtlLocation="/"+mtlLocation;
            if(mtlLocation[mtlLocation.size()-1] != '/')
                mtlLocation=mtlLocation+"/";

            DOUT << "mtlLocation : " << mtlLocation << std::endl;
            continue;
        }
        if(location[0]=='e')
        {//end
            break;
        }

        DOUT << "location : " << location << std::endl;
        //then we can break the loop and look for the scene parameters
        break;
    }

    ifs.close();

    loadObjects(directory+objLocation, directory+mtlLocation);

}


void Scene::loadObjects(const std::string path, const std::string mtlPath)
{
    std::vector<std::string> objFiles = getFileNames(path.c_str(), false, ".obj");

    std::string err;

    for(std::string& obj : objFiles){
        objects.push_back(Objects(obj,mtlPath));
    }

}




