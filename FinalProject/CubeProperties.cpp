#include "CubeProperties.h"

static char* allImages [][8] =
{
    //middleHallway
    {"/raws/james-madison-u.raw", "/raws/main_wall_brick.raw", "/raws/main_floor.raw", "/raws/james-madison-u.raw", "/raws/main_wall_brick.raw", "/raws/main_ceiling.raw"},
    
    //frontHallway
    {"/raws/exit_2704.raw", "/raws/plain_wall.raw", "/raws/left_hallways_floor.raw", "/raws/plain_wall.raw", "/raws/plain_wall.raw", "/raws/ceiling.raw"},
    
    //backHallway
    {"/raws/exit_2704.raw", "/raws/plain_wall.raw", "/raws/left_hallways_floor.raw", "/raws/grove_door_end.raw", "/raws/plain_wall.raw", "/raws/ceiling.raw"},
    
    //leftHallway
    {"/raws/exit_2704.raw","/raws/plain_wall.raw", "/raws/left_hallways_floor.raw","/raws/exit_2704.raw", "/raws/plain_wall.raw", "/raws/ceiling.raw"},
    
    //rightHallway
    {"/raws/exit_2704.raw", "/raws/plain_wall.raw",  "/raws/rug.raw","/raws/plain_wall.raw", "/raws/plain_wall.raw", "/raws/ceiling.raw"},
    
    //RoomWithBackAndSides
    {"/raws/plain_wall.raw", "/raws/plain_wall.raw",  "/raws/rug.raw","/raws/plain_wall.raw", "/raws/plain_wall.raw", "/raws/ceiling.raw"},
    
    //RoomWithBackAndSidesNORug
    {"/raws/plain_wall.raw", "/raws/plain_wall.raw",  "/raws/left_hallways_floor.raw","/raws/plain_wall.raw", "/raws/plain_wall.raw", "/raws/ceiling.raw"}
    
};


CubeProperties::CubeProperties()
{
    initializeFaces();
}

CubeProperties::CubeProperties(CubeProperties& properties)
{
    copyFaces(properties.faces);
    copyVertices(properties.vertices);
    copyImages(properties.images);
}

void CubeProperties::changeImage(Location location, char * image)
{
    int index;
    switch(location)
    {
        case CEILING:
            index =5;
            break;
        case FLOOR:
            index = 2;
            break;
        case FRONTWALL:
            index = 0;
            break;
        case BACKWALL:
            index = 4;
            break;
        case LEFTWALL:
            index = 1;
            break;
        case RIGHTWALL:
            index = 3;
            break;
        default:
            break;
    }
    
    if(index >= 0 && index < 6)
    {
        images[index] = image;
    }
    
    updateTextureMap();
}

void CubeProperties::copyFaces(GLint faces[6][4])
{
    for(int i =0; i < 6; i++)
    {
        for(int j =0; j < 4; j++)
        {
            this->faces[i][j] = faces[i][j];
        }
    }
}

void CubeProperties::copyImages(char * images[6])
{
    for(int i=0; i < 6; i++)
    {
        this->images[i] = images[i];
    }
    
    updateTextureMap();
}

void CubeProperties::copyVertices(GLfloat vertices[8][3])
{
    for(int i =0; i < 8; i++)
    {
        for(int j =0; j < 3; j++)
        {
            this->vertices[i][j] = vertices[i][j];
        }
    }
}

void CubeProperties::initializeFaces()
{
    for(int i =0; i < 6; i++)
    {
        switch(i)
        {
            case 0:
                faces[0][0] = 4;
                faces[0][1] = 5;
                faces[0][2] = 6;
                faces[0][3] = 7;
                break;
            case 1:
                faces[1][0] = 1;
                faces[1][1] = 2;
                faces[1][2] = 6;
                faces[1][3] = 5;
                break;
            case 2:
                faces[2][0] = 0;
                faces[2][1] = 1;
                faces[2][2] = 5;
                faces[2][3] = 4;
                break;
            case 3:
                faces[3][0] = 0;
                faces[3][1] = 3;
                faces[3][2] = 2;
                faces[3][3] = 1;
                break;
            case 4:
                faces[4][0] = 0;
                faces[4][1] = 4;
                faces[4][2] = 7;
                faces[4][3] = 3;
                break;
            case 5:
                faces[5][0] = 2;
                faces[5][1] = 3;
                faces[5][2] = 7;
                faces[5][3] = 6;
                break;
        }
    }
}

void CubeProperties::readRAWImage(char* filename, GLbyte data[256][256][3])
{
    FILE * file;
    
    file = fopen( filename, "rb" );
    if (file != NULL)
    {
        fread(data, 256 * 256 * 3, 1, file);
        fclose(file);
    }
}

void CubeProperties::setCubeImages(Position position)
{
    int index = 0;
    
    switch(position)
    {
        case BACKH:
            index = 2;
            break;
        case FRONTH:
            index = 1;
            break;
        case RIGHTH:
            index = 4;
            break;
        case LEFTH:
            index = 3;
            break;
        case MIDDLEH:
            index = 0;
            break;
    }
    for(int i =0; i < 6; i ++)
    {
        this->images[i] = allImages[index][i];
    }
}

void CubeProperties::setCubeVertices(GLfloat x, GLfloat y, GLfloat z)
{
    setVertices(x, y, z);
}

void CubeProperties::setFacesExcept(Faces f[], int size)
{
    for (int i =0; i <size; i ++)
    {
        switch(f[i])
        {
            case TOP:
                updateFaces(5);
                break;
            case BOTTOM:
                updateFaces(2);
                break;
            case RIGHT:
                updateFaces(1);
                break;
            case LEFT:
                updateFaces(4);
                break;
            case FRONT:
                updateFaces(0);
                break;
            case BACK:
                updateFaces(3);
                break;
        }
    }
}

void CubeProperties::setFacesExcept(Faces f)
{
    switch(f)
    {
        case TOP:
            updateFaces(5);
            break;
        case BOTTOM:
            updateFaces(2);
            break;
        case RIGHT:
            updateFaces(1);
            break;
        case LEFT:
            updateFaces(4);
            break;
        case FRONT:
            updateFaces(0);
            break;
        case BACK:
            updateFaces(3);
            break;
    }
}


void CubeProperties::setImages(Position pos)
{
    switch(pos)
    {
        case LEFTH:
            images[0] = allImages[3][0];
            images[1] = allImages[3][1];
            images[2] = allImages[3][2];
            images[3] = allImages[3][3];
            images[4] = allImages[3][4];
            images[5] = allImages[3][5];
            break;
        case RIGHTH:
            images[0] = allImages[4][0];
            images[1] = allImages[4][1];
            images[2] = allImages[4][2];
            images[3] = allImages[4][3];
            images[4] = allImages[4][4];
            images[5] = allImages[4][5];
            break;
        case MIDDLEH:
            images[0] = allImages[0][0];
            images[1] = allImages[0][1];
            images[2] = allImages[0][2];
            images[3] = allImages[0][3];
            images[4] = allImages[0][4];
            images[5] = allImages[0][5];
            break;
        case BACKH:
            images[0] = allImages[2][0];
            images[1] = allImages[2][1];
            images[2] = allImages[2][2];
            images[3] = allImages[2][3];
            images[4] = allImages[2][4];
            images[5] = allImages[2][5];
            break;
        case FRONTH:
            images[0] = allImages[1][0];
            images[1] = allImages[1][1];
            images[2] = allImages[1][2];
            images[3] = allImages[1][3];
            images[4] = allImages[1][4];
            images[5] = allImages[1][5];
            break;
        case ROOM_WITH_SIDES_AND_BACK:
            images[0] = allImages[5][0];
            images[1] = allImages[5][1];
            images[2] = allImages[5][2];
            images[3] = allImages[5][3];
            images[4] = allImages[5][4];
            images[5] = allImages[5][5];
            break;
            
        case ROOM_WITH_SIDES_AND_BACK_NO_RUG:
            images[0] = allImages[6][0];
            images[1] = allImages[6][1];
            images[2] = allImages[6][2];
            images[3] = allImages[6][3];
            images[4] = allImages[6][4];
            images[5] = allImages[6][5];
            break;
    }
    
    updateTextureMap();
}

void CubeProperties::setVertices(GLfloat x, GLfloat y, GLfloat z)
{
    for (int i =0; i < 8; i++)
    {
        switch(i)
        {
            case 0:
                vertices[0][0] = -x;
                vertices[0][1] = -y;
                vertices[0][2] = -z;
                break;
            case 1:
                vertices[1][0] = x;
                vertices[1][1] = -y;
                vertices[1][2] = -z;
                break;
            case 2:
                vertices[2][0] = x;
                vertices[2][1] = y;
                vertices[2][2] = -z;
                break;
            case 3:
                vertices[3][0] = -x;
                vertices[3][1] = y;
                vertices[3][2] = -z;
                break;
            case 4:
                vertices[4][0] = -x;
                vertices[4][1] = -y;
                vertices[4][2] = z;
                break;
            case 5:
                vertices[5][0] = x;
                vertices[5][1] = -y;
                vertices[5][2] = z;
                break;
            case 6:
                vertices[6][0] = x;
                vertices[6][1] = y;
                vertices[6][2] = z;
                break;
            case 7:
                vertices[7][0] = -x;
                vertices[7][1] = y;
                vertices[7][2] = z;
                break;
        }
    }
}
void CubeProperties::updateFaces(int row)
{
    for(int i =0; i < 4; i++)
    {
        this->faces[row][i] = -1;
    }
}

void CubeProperties::updateTextureMap()
{
    //Read the "image"
    GLbyte image[6][256][256][3];
    
    //read in each raw image for the cube
    for(int i =0; i < 6; i++)
    {
        readRAWImage(images[i], image[i]);
    }
    
    //[name
    // Get a name for the texture
    glGenTextures(6, textureNames);
    //]name
    
    for (int i=0; i<6; i++)
    {
        // Select the texture object
        glBindTexture(GL_TEXTURE_2D, textureNames[i]);
        
        // Set the parameters
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        
        // Create the texture object
        glTexImage2D(GL_TEXTURE_2D,0,3,256,256,0,GL_RGB,GL_UNSIGNED_BYTE,
                     image[i]);
    }
    
    // Enable textures
    glEnable(GL_TEXTURE_2D);

}