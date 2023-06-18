#ifndef _ROS_moveit_task_constructor_msgs_StageDescription_h
#define _ROS_moveit_task_constructor_msgs_StageDescription_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_task_constructor_msgs/Property.h"

namespace moveit_task_constructor_msgs
{

  class StageDescription : public ros::Msg
  {
    public:
      typedef uint32_t _id_type;
      _id_type id;
      typedef uint32_t _parent_id_type;
      _parent_id_type parent_id;
      typedef const char* _name_type;
      _name_type name;
      typedef uint32_t _flags_type;
      _flags_type flags;
      uint32_t properties_length;
      typedef moveit_task_constructor_msgs::Property _properties_type;
      _properties_type st_properties;
      _properties_type * properties;

    StageDescription():
      id(0),
      parent_id(0),
      name(""),
      flags(0),
      properties_length(0), st_properties(), properties(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->parent_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->parent_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->parent_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->parent_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->parent_id);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset + 0) = (this->flags >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->flags >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->flags >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->flags >> (8 * 3)) & 0xFF;
      offset += sizeof(this->flags);
      *(outbuffer + offset + 0) = (this->properties_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->properties_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->properties_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->properties_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->properties_length);
      for( uint32_t i = 0; i < properties_length; i++){
      offset += this->properties[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      this->parent_id =  ((uint32_t) (*(inbuffer + offset)));
      this->parent_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->parent_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->parent_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->parent_id);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      this->flags =  ((uint32_t) (*(inbuffer + offset)));
      this->flags |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->flags |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->flags |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->flags);
      uint32_t properties_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      properties_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      properties_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      properties_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->properties_length);
      if(properties_lengthT > properties_length)
        this->properties = (moveit_task_constructor_msgs::Property*)realloc(this->properties, properties_lengthT * sizeof(moveit_task_constructor_msgs::Property));
      properties_length = properties_lengthT;
      for( uint32_t i = 0; i < properties_length; i++){
      offset += this->st_properties.deserialize(inbuffer + offset);
        memcpy( &(this->properties[i]), &(this->st_properties), sizeof(moveit_task_constructor_msgs::Property));
      }
     return offset;
    }

    virtual const char * getType() override { return "moveit_task_constructor_msgs/StageDescription"; };
    virtual const char * getMD5() override { return "eae8b915a082df4d70b7bbf2530bd3fd"; };

  };

}
#endif
