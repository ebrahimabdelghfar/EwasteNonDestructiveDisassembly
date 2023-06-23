#ifndef _ROS_rm_msgs_ActuatorState_h
#define _ROS_rm_msgs_ActuatorState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace rm_msgs
{

  class ActuatorState : public ros::Msg
  {
    public:
      uint32_t stamp_length;
      typedef ros::Time _stamp_type;
      _stamp_type st_stamp;
      _stamp_type * stamp;
      uint32_t name_length;
      typedef char* _name_type;
      _name_type st_name;
      _name_type * name;
      uint32_t type_length;
      typedef char* _type_type;
      _type_type st_type;
      _type_type * type;
      uint32_t bus_length;
      typedef char* _bus_type;
      _bus_type st_bus;
      _bus_type * bus;
      uint32_t id_length;
      typedef int32_t _id_type;
      _id_type st_id;
      _id_type * id;
      uint32_t halted_length;
      typedef bool _halted_type;
      _halted_type st_halted;
      _halted_type * halted;
      uint32_t need_calibration_length;
      typedef bool _need_calibration_type;
      _need_calibration_type st_need_calibration;
      _need_calibration_type * need_calibration;
      uint32_t calibrated_length;
      typedef bool _calibrated_type;
      _calibrated_type st_calibrated;
      _calibrated_type * calibrated;
      uint32_t calibration_reading_length;
      typedef bool _calibration_reading_type;
      _calibration_reading_type st_calibration_reading;
      _calibration_reading_type * calibration_reading;
      uint32_t position_raw_length;
      typedef uint16_t _position_raw_type;
      _position_raw_type st_position_raw;
      _position_raw_type * position_raw;
      uint32_t velocity_raw_length;
      typedef int16_t _velocity_raw_type;
      _velocity_raw_type st_velocity_raw;
      _velocity_raw_type * velocity_raw;
      uint32_t temperature_length;
      typedef uint8_t _temperature_type;
      _temperature_type st_temperature;
      _temperature_type * temperature;
      uint32_t circle_length;
      typedef int64_t _circle_type;
      _circle_type st_circle;
      _circle_type * circle;
      uint32_t last_position_raw_length;
      typedef uint16_t _last_position_raw_type;
      _last_position_raw_type st_last_position_raw;
      _last_position_raw_type * last_position_raw;
      uint32_t frequency_length;
      typedef double _frequency_type;
      _frequency_type st_frequency;
      _frequency_type * frequency;
      uint32_t position_length;
      typedef double _position_type;
      _position_type st_position;
      _position_type * position;
      uint32_t velocity_length;
      typedef double _velocity_type;
      _velocity_type st_velocity;
      _velocity_type * velocity;
      uint32_t effort_length;
      typedef double _effort_type;
      _effort_type st_effort;
      _effort_type * effort;
      uint32_t commanded_effort_length;
      typedef double _commanded_effort_type;
      _commanded_effort_type st_commanded_effort;
      _commanded_effort_type * commanded_effort;
      uint32_t executed_effort_length;
      typedef double _executed_effort_type;
      _executed_effort_type st_executed_effort;
      _executed_effort_type * executed_effort;
      uint32_t offset_length;
      typedef double _offset_type;
      _offset_type st_offset;
      _offset_type * offset;

    ActuatorState():
      stamp_length(0), st_stamp(), stamp(nullptr),
      name_length(0), st_name(), name(nullptr),
      type_length(0), st_type(), type(nullptr),
      bus_length(0), st_bus(), bus(nullptr),
      id_length(0), st_id(), id(nullptr),
      halted_length(0), st_halted(), halted(nullptr),
      need_calibration_length(0), st_need_calibration(), need_calibration(nullptr),
      calibrated_length(0), st_calibrated(), calibrated(nullptr),
      calibration_reading_length(0), st_calibration_reading(), calibration_reading(nullptr),
      position_raw_length(0), st_position_raw(), position_raw(nullptr),
      velocity_raw_length(0), st_velocity_raw(), velocity_raw(nullptr),
      temperature_length(0), st_temperature(), temperature(nullptr),
      circle_length(0), st_circle(), circle(nullptr),
      last_position_raw_length(0), st_last_position_raw(), last_position_raw(nullptr),
      frequency_length(0), st_frequency(), frequency(nullptr),
      position_length(0), st_position(), position(nullptr),
      velocity_length(0), st_velocity(), velocity(nullptr),
      effort_length(0), st_effort(), effort(nullptr),
      commanded_effort_length(0), st_commanded_effort(), commanded_effort(nullptr),
      executed_effort_length(0), st_executed_effort(), executed_effort(nullptr),
      offset_length(0), st_offset(), offset(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->stamp_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp_length);
      for( uint32_t i = 0; i < stamp_length; i++){
      *(outbuffer + offset + 0) = (this->stamp[i].sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp[i].sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp[i].sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp[i].sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp[i].sec);
      *(outbuffer + offset + 0) = (this->stamp[i].nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp[i].nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp[i].nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp[i].nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp[i].nsec);
      }
      *(outbuffer + offset + 0) = (this->name_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->name_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->name_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->name_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->name_length);
      for( uint32_t i = 0; i < name_length; i++){
      uint32_t length_namei = strlen(this->name[i]);
      varToArr(outbuffer + offset, length_namei);
      offset += 4;
      memcpy(outbuffer + offset, this->name[i], length_namei);
      offset += length_namei;
      }
      *(outbuffer + offset + 0) = (this->type_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->type_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->type_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->type_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type_length);
      for( uint32_t i = 0; i < type_length; i++){
      uint32_t length_typei = strlen(this->type[i]);
      varToArr(outbuffer + offset, length_typei);
      offset += 4;
      memcpy(outbuffer + offset, this->type[i], length_typei);
      offset += length_typei;
      }
      *(outbuffer + offset + 0) = (this->bus_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->bus_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->bus_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->bus_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bus_length);
      for( uint32_t i = 0; i < bus_length; i++){
      uint32_t length_busi = strlen(this->bus[i]);
      varToArr(outbuffer + offset, length_busi);
      offset += 4;
      memcpy(outbuffer + offset, this->bus[i], length_busi);
      offset += length_busi;
      }
      *(outbuffer + offset + 0) = (this->id_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id_length);
      for( uint32_t i = 0; i < id_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_idi;
      u_idi.real = this->id[i];
      *(outbuffer + offset + 0) = (u_idi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_idi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_idi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_idi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id[i]);
      }
      *(outbuffer + offset + 0) = (this->halted_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->halted_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->halted_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->halted_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->halted_length);
      for( uint32_t i = 0; i < halted_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_haltedi;
      u_haltedi.real = this->halted[i];
      *(outbuffer + offset + 0) = (u_haltedi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->halted[i]);
      }
      *(outbuffer + offset + 0) = (this->need_calibration_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->need_calibration_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->need_calibration_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->need_calibration_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->need_calibration_length);
      for( uint32_t i = 0; i < need_calibration_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_need_calibrationi;
      u_need_calibrationi.real = this->need_calibration[i];
      *(outbuffer + offset + 0) = (u_need_calibrationi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->need_calibration[i]);
      }
      *(outbuffer + offset + 0) = (this->calibrated_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->calibrated_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->calibrated_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->calibrated_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->calibrated_length);
      for( uint32_t i = 0; i < calibrated_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_calibratedi;
      u_calibratedi.real = this->calibrated[i];
      *(outbuffer + offset + 0) = (u_calibratedi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->calibrated[i]);
      }
      *(outbuffer + offset + 0) = (this->calibration_reading_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->calibration_reading_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->calibration_reading_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->calibration_reading_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->calibration_reading_length);
      for( uint32_t i = 0; i < calibration_reading_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_calibration_readingi;
      u_calibration_readingi.real = this->calibration_reading[i];
      *(outbuffer + offset + 0) = (u_calibration_readingi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->calibration_reading[i]);
      }
      *(outbuffer + offset + 0) = (this->position_raw_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->position_raw_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->position_raw_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->position_raw_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position_raw_length);
      for( uint32_t i = 0; i < position_raw_length; i++){
      *(outbuffer + offset + 0) = (this->position_raw[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->position_raw[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->position_raw[i]);
      }
      *(outbuffer + offset + 0) = (this->velocity_raw_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->velocity_raw_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->velocity_raw_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->velocity_raw_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_raw_length);
      for( uint32_t i = 0; i < velocity_raw_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_velocity_rawi;
      u_velocity_rawi.real = this->velocity_raw[i];
      *(outbuffer + offset + 0) = (u_velocity_rawi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_rawi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->velocity_raw[i]);
      }
      *(outbuffer + offset + 0) = (this->temperature_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->temperature_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->temperature_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->temperature_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temperature_length);
      for( uint32_t i = 0; i < temperature_length; i++){
      *(outbuffer + offset + 0) = (this->temperature[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->temperature[i]);
      }
      *(outbuffer + offset + 0) = (this->circle_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->circle_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->circle_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->circle_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->circle_length);
      for( uint32_t i = 0; i < circle_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_circlei;
      u_circlei.real = this->circle[i];
      *(outbuffer + offset + 0) = (u_circlei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_circlei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_circlei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_circlei.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_circlei.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_circlei.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_circlei.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_circlei.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->circle[i]);
      }
      *(outbuffer + offset + 0) = (this->last_position_raw_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->last_position_raw_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->last_position_raw_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->last_position_raw_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->last_position_raw_length);
      for( uint32_t i = 0; i < last_position_raw_length; i++){
      *(outbuffer + offset + 0) = (this->last_position_raw[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->last_position_raw[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->last_position_raw[i]);
      }
      *(outbuffer + offset + 0) = (this->frequency_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->frequency_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->frequency_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->frequency_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->frequency_length);
      for( uint32_t i = 0; i < frequency_length; i++){
      union {
        double real;
        uint64_t base;
      } u_frequencyi;
      u_frequencyi.real = this->frequency[i];
      *(outbuffer + offset + 0) = (u_frequencyi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_frequencyi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_frequencyi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_frequencyi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_frequencyi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_frequencyi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_frequencyi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_frequencyi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->frequency[i]);
      }
      *(outbuffer + offset + 0) = (this->position_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->position_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->position_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->position_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position_length);
      for( uint32_t i = 0; i < position_length; i++){
      union {
        double real;
        uint64_t base;
      } u_positioni;
      u_positioni.real = this->position[i];
      *(outbuffer + offset + 0) = (u_positioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_positioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_positioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_positioni.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_positioni.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_positioni.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_positioni.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_positioni.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->position[i]);
      }
      *(outbuffer + offset + 0) = (this->velocity_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->velocity_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->velocity_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->velocity_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_length);
      for( uint32_t i = 0; i < velocity_length; i++){
      union {
        double real;
        uint64_t base;
      } u_velocityi;
      u_velocityi.real = this->velocity[i];
      *(outbuffer + offset + 0) = (u_velocityi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocityi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocityi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocityi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_velocityi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_velocityi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_velocityi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_velocityi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->velocity[i]);
      }
      *(outbuffer + offset + 0) = (this->effort_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->effort_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->effort_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->effort_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->effort_length);
      for( uint32_t i = 0; i < effort_length; i++){
      union {
        double real;
        uint64_t base;
      } u_efforti;
      u_efforti.real = this->effort[i];
      *(outbuffer + offset + 0) = (u_efforti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_efforti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_efforti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_efforti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_efforti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_efforti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_efforti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_efforti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->effort[i]);
      }
      *(outbuffer + offset + 0) = (this->commanded_effort_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->commanded_effort_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->commanded_effort_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->commanded_effort_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->commanded_effort_length);
      for( uint32_t i = 0; i < commanded_effort_length; i++){
      union {
        double real;
        uint64_t base;
      } u_commanded_efforti;
      u_commanded_efforti.real = this->commanded_effort[i];
      *(outbuffer + offset + 0) = (u_commanded_efforti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_commanded_efforti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_commanded_efforti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_commanded_efforti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_commanded_efforti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_commanded_efforti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_commanded_efforti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_commanded_efforti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->commanded_effort[i]);
      }
      *(outbuffer + offset + 0) = (this->executed_effort_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->executed_effort_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->executed_effort_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->executed_effort_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->executed_effort_length);
      for( uint32_t i = 0; i < executed_effort_length; i++){
      union {
        double real;
        uint64_t base;
      } u_executed_efforti;
      u_executed_efforti.real = this->executed_effort[i];
      *(outbuffer + offset + 0) = (u_executed_efforti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_executed_efforti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_executed_efforti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_executed_efforti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_executed_efforti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_executed_efforti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_executed_efforti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_executed_efforti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->executed_effort[i]);
      }
      *(outbuffer + offset + 0) = (this->offset_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->offset_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->offset_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->offset_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->offset_length);
      for( uint32_t i = 0; i < offset_length; i++){
      union {
        double real;
        uint64_t base;
      } u_offseti;
      u_offseti.real = this->offset[i];
      *(outbuffer + offset + 0) = (u_offseti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_offseti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_offseti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_offseti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_offseti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_offseti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_offseti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_offseti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->offset[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t stamp_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      stamp_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      stamp_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      stamp_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->stamp_length);
      if(stamp_lengthT > stamp_length)
        this->stamp = (ros::Time*)realloc(this->stamp, stamp_lengthT * sizeof(ros::Time));
      stamp_length = stamp_lengthT;
      for( uint32_t i = 0; i < stamp_length; i++){
      this->st_stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->st_stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_stamp.sec);
      this->st_stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->st_stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_stamp.nsec);
        memcpy( &(this->stamp[i]), &(this->st_stamp), sizeof(ros::Time));
      }
      uint32_t name_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->name_length);
      if(name_lengthT > name_length)
        this->name = (char**)realloc(this->name, name_lengthT * sizeof(char*));
      name_length = name_lengthT;
      for( uint32_t i = 0; i < name_length; i++){
      uint32_t length_st_name;
      arrToVar(length_st_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_name-1]=0;
      this->st_name = (char *)(inbuffer + offset-1);
      offset += length_st_name;
        memcpy( &(this->name[i]), &(this->st_name), sizeof(char*));
      }
      uint32_t type_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      type_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      type_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      type_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->type_length);
      if(type_lengthT > type_length)
        this->type = (char**)realloc(this->type, type_lengthT * sizeof(char*));
      type_length = type_lengthT;
      for( uint32_t i = 0; i < type_length; i++){
      uint32_t length_st_type;
      arrToVar(length_st_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_type-1]=0;
      this->st_type = (char *)(inbuffer + offset-1);
      offset += length_st_type;
        memcpy( &(this->type[i]), &(this->st_type), sizeof(char*));
      }
      uint32_t bus_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      bus_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      bus_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      bus_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->bus_length);
      if(bus_lengthT > bus_length)
        this->bus = (char**)realloc(this->bus, bus_lengthT * sizeof(char*));
      bus_length = bus_lengthT;
      for( uint32_t i = 0; i < bus_length; i++){
      uint32_t length_st_bus;
      arrToVar(length_st_bus, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_bus; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_bus-1]=0;
      this->st_bus = (char *)(inbuffer + offset-1);
      offset += length_st_bus;
        memcpy( &(this->bus[i]), &(this->st_bus), sizeof(char*));
      }
      uint32_t id_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      id_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      id_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      id_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->id_length);
      if(id_lengthT > id_length)
        this->id = (int32_t*)realloc(this->id, id_lengthT * sizeof(int32_t));
      id_length = id_lengthT;
      for( uint32_t i = 0; i < id_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_id;
      u_st_id.base = 0;
      u_st_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_id = u_st_id.real;
      offset += sizeof(this->st_id);
        memcpy( &(this->id[i]), &(this->st_id), sizeof(int32_t));
      }
      uint32_t halted_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      halted_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      halted_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      halted_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->halted_length);
      if(halted_lengthT > halted_length)
        this->halted = (bool*)realloc(this->halted, halted_lengthT * sizeof(bool));
      halted_length = halted_lengthT;
      for( uint32_t i = 0; i < halted_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_halted;
      u_st_halted.base = 0;
      u_st_halted.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_halted = u_st_halted.real;
      offset += sizeof(this->st_halted);
        memcpy( &(this->halted[i]), &(this->st_halted), sizeof(bool));
      }
      uint32_t need_calibration_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      need_calibration_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      need_calibration_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      need_calibration_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->need_calibration_length);
      if(need_calibration_lengthT > need_calibration_length)
        this->need_calibration = (bool*)realloc(this->need_calibration, need_calibration_lengthT * sizeof(bool));
      need_calibration_length = need_calibration_lengthT;
      for( uint32_t i = 0; i < need_calibration_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_need_calibration;
      u_st_need_calibration.base = 0;
      u_st_need_calibration.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_need_calibration = u_st_need_calibration.real;
      offset += sizeof(this->st_need_calibration);
        memcpy( &(this->need_calibration[i]), &(this->st_need_calibration), sizeof(bool));
      }
      uint32_t calibrated_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      calibrated_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      calibrated_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      calibrated_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->calibrated_length);
      if(calibrated_lengthT > calibrated_length)
        this->calibrated = (bool*)realloc(this->calibrated, calibrated_lengthT * sizeof(bool));
      calibrated_length = calibrated_lengthT;
      for( uint32_t i = 0; i < calibrated_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_calibrated;
      u_st_calibrated.base = 0;
      u_st_calibrated.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_calibrated = u_st_calibrated.real;
      offset += sizeof(this->st_calibrated);
        memcpy( &(this->calibrated[i]), &(this->st_calibrated), sizeof(bool));
      }
      uint32_t calibration_reading_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      calibration_reading_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      calibration_reading_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      calibration_reading_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->calibration_reading_length);
      if(calibration_reading_lengthT > calibration_reading_length)
        this->calibration_reading = (bool*)realloc(this->calibration_reading, calibration_reading_lengthT * sizeof(bool));
      calibration_reading_length = calibration_reading_lengthT;
      for( uint32_t i = 0; i < calibration_reading_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_calibration_reading;
      u_st_calibration_reading.base = 0;
      u_st_calibration_reading.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_calibration_reading = u_st_calibration_reading.real;
      offset += sizeof(this->st_calibration_reading);
        memcpy( &(this->calibration_reading[i]), &(this->st_calibration_reading), sizeof(bool));
      }
      uint32_t position_raw_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      position_raw_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      position_raw_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      position_raw_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->position_raw_length);
      if(position_raw_lengthT > position_raw_length)
        this->position_raw = (uint16_t*)realloc(this->position_raw, position_raw_lengthT * sizeof(uint16_t));
      position_raw_length = position_raw_lengthT;
      for( uint32_t i = 0; i < position_raw_length; i++){
      this->st_position_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->st_position_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->st_position_raw);
        memcpy( &(this->position_raw[i]), &(this->st_position_raw), sizeof(uint16_t));
      }
      uint32_t velocity_raw_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      velocity_raw_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      velocity_raw_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      velocity_raw_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->velocity_raw_length);
      if(velocity_raw_lengthT > velocity_raw_length)
        this->velocity_raw = (int16_t*)realloc(this->velocity_raw, velocity_raw_lengthT * sizeof(int16_t));
      velocity_raw_length = velocity_raw_lengthT;
      for( uint32_t i = 0; i < velocity_raw_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_velocity_raw;
      u_st_velocity_raw.base = 0;
      u_st_velocity_raw.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_velocity_raw.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_velocity_raw = u_st_velocity_raw.real;
      offset += sizeof(this->st_velocity_raw);
        memcpy( &(this->velocity_raw[i]), &(this->st_velocity_raw), sizeof(int16_t));
      }
      uint32_t temperature_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      temperature_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      temperature_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      temperature_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->temperature_length);
      if(temperature_lengthT > temperature_length)
        this->temperature = (uint8_t*)realloc(this->temperature, temperature_lengthT * sizeof(uint8_t));
      temperature_length = temperature_lengthT;
      for( uint32_t i = 0; i < temperature_length; i++){
      this->st_temperature =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_temperature);
        memcpy( &(this->temperature[i]), &(this->st_temperature), sizeof(uint8_t));
      }
      uint32_t circle_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      circle_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      circle_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      circle_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->circle_length);
      if(circle_lengthT > circle_length)
        this->circle = (int64_t*)realloc(this->circle, circle_lengthT * sizeof(int64_t));
      circle_length = circle_lengthT;
      for( uint32_t i = 0; i < circle_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_circle;
      u_st_circle.base = 0;
      u_st_circle.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_circle.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_circle.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_circle.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_circle.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_circle.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_circle.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_circle.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_circle = u_st_circle.real;
      offset += sizeof(this->st_circle);
        memcpy( &(this->circle[i]), &(this->st_circle), sizeof(int64_t));
      }
      uint32_t last_position_raw_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      last_position_raw_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      last_position_raw_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      last_position_raw_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->last_position_raw_length);
      if(last_position_raw_lengthT > last_position_raw_length)
        this->last_position_raw = (uint16_t*)realloc(this->last_position_raw, last_position_raw_lengthT * sizeof(uint16_t));
      last_position_raw_length = last_position_raw_lengthT;
      for( uint32_t i = 0; i < last_position_raw_length; i++){
      this->st_last_position_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->st_last_position_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->st_last_position_raw);
        memcpy( &(this->last_position_raw[i]), &(this->st_last_position_raw), sizeof(uint16_t));
      }
      uint32_t frequency_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      frequency_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      frequency_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      frequency_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->frequency_length);
      if(frequency_lengthT > frequency_length)
        this->frequency = (double*)realloc(this->frequency, frequency_lengthT * sizeof(double));
      frequency_length = frequency_lengthT;
      for( uint32_t i = 0; i < frequency_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_frequency;
      u_st_frequency.base = 0;
      u_st_frequency.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_frequency.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_frequency.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_frequency.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_frequency.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_frequency.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_frequency.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_frequency.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_frequency = u_st_frequency.real;
      offset += sizeof(this->st_frequency);
        memcpy( &(this->frequency[i]), &(this->st_frequency), sizeof(double));
      }
      uint32_t position_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      position_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      position_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      position_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->position_length);
      if(position_lengthT > position_length)
        this->position = (double*)realloc(this->position, position_lengthT * sizeof(double));
      position_length = position_lengthT;
      for( uint32_t i = 0; i < position_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_position;
      u_st_position.base = 0;
      u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_position = u_st_position.real;
      offset += sizeof(this->st_position);
        memcpy( &(this->position[i]), &(this->st_position), sizeof(double));
      }
      uint32_t velocity_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->velocity_length);
      if(velocity_lengthT > velocity_length)
        this->velocity = (double*)realloc(this->velocity, velocity_lengthT * sizeof(double));
      velocity_length = velocity_lengthT;
      for( uint32_t i = 0; i < velocity_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_velocity;
      u_st_velocity.base = 0;
      u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_velocity = u_st_velocity.real;
      offset += sizeof(this->st_velocity);
        memcpy( &(this->velocity[i]), &(this->st_velocity), sizeof(double));
      }
      uint32_t effort_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->effort_length);
      if(effort_lengthT > effort_length)
        this->effort = (double*)realloc(this->effort, effort_lengthT * sizeof(double));
      effort_length = effort_lengthT;
      for( uint32_t i = 0; i < effort_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_effort;
      u_st_effort.base = 0;
      u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_effort = u_st_effort.real;
      offset += sizeof(this->st_effort);
        memcpy( &(this->effort[i]), &(this->st_effort), sizeof(double));
      }
      uint32_t commanded_effort_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      commanded_effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      commanded_effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      commanded_effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->commanded_effort_length);
      if(commanded_effort_lengthT > commanded_effort_length)
        this->commanded_effort = (double*)realloc(this->commanded_effort, commanded_effort_lengthT * sizeof(double));
      commanded_effort_length = commanded_effort_lengthT;
      for( uint32_t i = 0; i < commanded_effort_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_commanded_effort;
      u_st_commanded_effort.base = 0;
      u_st_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_commanded_effort = u_st_commanded_effort.real;
      offset += sizeof(this->st_commanded_effort);
        memcpy( &(this->commanded_effort[i]), &(this->st_commanded_effort), sizeof(double));
      }
      uint32_t executed_effort_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      executed_effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      executed_effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      executed_effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->executed_effort_length);
      if(executed_effort_lengthT > executed_effort_length)
        this->executed_effort = (double*)realloc(this->executed_effort, executed_effort_lengthT * sizeof(double));
      executed_effort_length = executed_effort_lengthT;
      for( uint32_t i = 0; i < executed_effort_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_executed_effort;
      u_st_executed_effort.base = 0;
      u_st_executed_effort.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_executed_effort.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_executed_effort.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_executed_effort.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_executed_effort.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_executed_effort.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_executed_effort.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_executed_effort.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_executed_effort = u_st_executed_effort.real;
      offset += sizeof(this->st_executed_effort);
        memcpy( &(this->executed_effort[i]), &(this->st_executed_effort), sizeof(double));
      }
      uint32_t offset_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      offset_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      offset_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      offset_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->offset_length);
      if(offset_lengthT > offset_length)
        this->offset = (double*)realloc(this->offset, offset_lengthT * sizeof(double));
      offset_length = offset_lengthT;
      for( uint32_t i = 0; i < offset_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_offset;
      u_st_offset.base = 0;
      u_st_offset.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_offset.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_offset.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_offset.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_offset.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_offset.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_offset.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_offset.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_offset = u_st_offset.real;
      offset += sizeof(this->st_offset);
        memcpy( &(this->offset[i]), &(this->st_offset), sizeof(double));
      }
     return offset;
    }

    virtual const char * getType() override { return "rm_msgs/ActuatorState"; };
    virtual const char * getMD5() override { return "f82106ab641e97268a9e8e29a4b47321"; };

  };

}
#endif
