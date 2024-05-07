#include <stdio.h>
#include <assimp/cimport.h>     // Plain-C interface
#include <assimp/scene.h>       // Output data structure
#include <assimp/postprocess.h> // Post processing flags

int main(int argc, char **argv)
{
    // Start the import on the given file with some example postprocessing
    // Usually - if speed is not the most important aspect for you - you'll t
    // probably to request more postprocessing than we do in this example.
    const struct aiScene *scene = aiImportFile("demo",
                                               aiProcess_CalcTangentSpace |
                                                   aiProcess_Triangulate |
                                                   aiProcess_JoinIdenticalVertices |
                                                   aiProcess_SortByPType);

    printf("size of ai_real: %d\n", sizeof(ai_real));

    if (scene)
    {
        int num_meshes = scene->mNumMeshes;
        printf("number of meshes: %d\n", num_meshes);
    }
    else
    {
        printf("scene is null");
    }

    aiReleaseImport(scene);
    return 0;
}
