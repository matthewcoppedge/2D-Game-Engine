#include "GLTexture.h"

GLTexture::GLTexture()
{
    //ctor
}

GLTexture::~GLTexture()
{
    //dtor
}

void GLTexture::loadTexture(char* fileName)
{
    glGenTextures(1, &tex);                                                                         //Generating texture/image handler
    glBindTexture(GL_TEXTURE_2D, tex);                                                              //Pointing handler to the texture data format

    image = SOIL_load_image(fileName, &width, &height, 0, SOIL_LOAD_RGBA);                          //Read image
    if (!image) cout << "ERROR: " << fileName << " not found!" << endl;                                          //Error check

    if (!image) cout << "ERROR: << " << fileName <<  " not found!" << endl;                         //Error check

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);    //store image

    SOIL_free_image_data(image);                                         //delete image holder                                                 //

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);        //how to wrap on object in x dir
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);        //how to wrap on object in y dir
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);    //decide quality of the image
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);    //decide quality of the image

}

void GLTexture::bindTexture()
{
    glBindTexture(GL_TEXTURE_2D, tex);
}
