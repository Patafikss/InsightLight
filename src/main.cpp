#include <iostream>
#include <algorithm>
#include "fileutils.h"
#include "scene.h"
#include "defs.h"


using namespace std;

int main(int argc,char **argv)
{
    //this throws error when executed the path has no '/'
    //simply removes the name of the program executed
    std::string path(argv[0]);
    std::replace(path.begin(),path.end(),'\\','/');
    path=path.substr(0,path.find_last_of('/')+1);

    if(argc<=1)
    {
        std::cerr << "The path to the scene file is needed" << std::endl;
        return EXIT_FAILURE;
    }

    //get the path to the scene file
    std::string filepath = AddFilePath(path.c_str(),argv[1]);
    Scene s;
    s.loadScene(filepath);

    return 0;
}

/*
  if (!err.empty()) { // `err` may contain warning message.
      std::cerr << err << std::endl;
    }

    if (!ret) {
      exit(1);
    }

    // Loop over shapes
    for (size_t s = 0; s < shapes.size(); s++) {
      // Loop over faces(polygon)
      size_t index_offset = 0;
      for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
        int fv = shapes[s].mesh.num_face_vertices[f];

        // Loop over vertices in the face.
        for (size_t v = 0; v < fv; v++) {
          // access to vertex
          tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
          tinyobj::real_t vx = attrib.vertices[3*idx.vertex_index+0];
          tinyobj::real_t vy = attrib.vertices[3*idx.vertex_index+1];
          tinyobj::real_t vz = attrib.vertices[3*idx.vertex_index+2];
          tinyobj::real_t nx = attrib.normals[3*idx.normal_index+0];
          tinyobj::real_t ny = attrib.normals[3*idx.normal_index+1];
          tinyobj::real_t nz = attrib.normals[3*idx.normal_index+2];
          tinyobj::real_t tx = attrib.texcoords[2*idx.texcoord_index+0];
          tinyobj::real_t ty = attrib.texcoords[2*idx.texcoord_index+1];
          // Optional: vertex colors
          // tinyobj::real_t red = attrib.colors[3*idx.vertex_index+0];
          // tinyobj::real_t green = attrib.colors[3*idx.vertex_index+1];
          // tinyobj::real_t blue = attrib.colors[3*idx.vertex_index+2];
        }
        index_offset += fv;
        // per-face material
        shapes[s].mesh.material_ids[f];
      }
    }
*/
