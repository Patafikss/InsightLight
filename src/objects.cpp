#include "objects.h"
#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>

Objects::Objects(const std::string &objFile, const std::string &mtlDirectory)
    :m_filename(objFile)
{
    loadObject(objFile,mtlDirectory);
}

Objects::loadObject(const std::string &objFile,const std::string &mtlDirectory)
{
    m_filename = objFile;
    std::string err;
    bool ret = tinyobj::LoadObj(&m_attrib, &m_shapes, &m_materials, &err, objFile.c_str(), mtlDirectory.c_str());
    if(!err.empty())
        std::cerr<<"tinyobj : "<<err<<std::endl;
    if(ret)
        std::cout<<"Parsing "<<objFile<< " success"<<std::endl;
    Matrix4f m;
    m_transformations.push_back(m);
}
