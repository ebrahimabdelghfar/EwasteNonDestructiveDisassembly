#ifndef _ROS_rm_msgs_BalanceState_h
#define _ROS_rm_msgs_BalanceState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rm_msgs
{

  class BalanceState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _x_type;
      _x_type x;
      typedef double _phi_type;
      _phi_type phi;
      typedef double _theta_type;
      _theta_type theta;
      typedef double _x_b_l_type;
      _x_b_l_type x_b_l;
      typedef double _x_b_r_type;
      _x_b_r_type x_b_r;
      typedef double _x_dot_type;
      _x_dot_type x_dot;
      typedef double _phi_dot_type;
      _phi_dot_type phi_dot;
      typedef double _theta_dot_type;
      _theta_dot_type theta_dot;
      typedef double _x_b_l_dot_type;
      _x_b_l_dot_type x_b_l_dot;
      typedef double _x_b_r_dot_type;
      _x_b_r_dot_type x_b_r_dot;
      typedef double _T_l_type;
      _T_l_type T_l;
      typedef double _T_r_type;
      _T_r_type T_r;
      typedef double _f_b_l_type;
      _f_b_l_type f_b_l;
      typedef double _f_b_r_type;
      _f_b_r_type f_b_r;

    BalanceState():
      header(),
      x(0),
      phi(0),
      theta(0),
      x_b_l(0),
      x_b_r(0),
      x_dot(0),
      phi_dot(0),
      theta_dot(0),
      x_b_l_dot(0),
      x_b_r_dot(0),
      T_l(0),
      T_r(0),
      f_b_l(0),
      f_b_r(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x);
      union {
        double real;
        uint64_t base;
      } u_phi;
      u_phi.real = this->phi;
      *(outbuffer + offset + 0) = (u_phi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_phi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_phi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_phi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_phi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_phi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_phi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_phi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->phi);
      union {
        double real;
        uint64_t base;
      } u_theta;
      u_theta.real = this->theta;
      *(outbuffer + offset + 0) = (u_theta.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_theta.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_theta.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_theta.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_theta.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_theta.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_theta.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_theta.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->theta);
      union {
        double real;
        uint64_t base;
      } u_x_b_l;
      u_x_b_l.real = this->x_b_l;
      *(outbuffer + offset + 0) = (u_x_b_l.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x_b_l.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x_b_l.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x_b_l.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_x_b_l.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_x_b_l.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_x_b_l.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_x_b_l.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x_b_l);
      union {
        double real;
        uint64_t base;
      } u_x_b_r;
      u_x_b_r.real = this->x_b_r;
      *(outbuffer + offset + 0) = (u_x_b_r.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x_b_r.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x_b_r.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x_b_r.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_x_b_r.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_x_b_r.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_x_b_r.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_x_b_r.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x_b_r);
      union {
        double real;
        uint64_t base;
      } u_x_dot;
      u_x_dot.real = this->x_dot;
      *(outbuffer + offset + 0) = (u_x_dot.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x_dot.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x_dot.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x_dot.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_x_dot.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_x_dot.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_x_dot.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_x_dot.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x_dot);
      union {
        double real;
        uint64_t base;
      } u_phi_dot;
      u_phi_dot.real = this->phi_dot;
      *(outbuffer + offset + 0) = (u_phi_dot.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_phi_dot.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_phi_dot.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_phi_dot.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_phi_dot.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_phi_dot.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_phi_dot.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_phi_dot.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->phi_dot);
      union {
        double real;
        uint64_t base;
      } u_theta_dot;
      u_theta_dot.real = this->theta_dot;
      *(outbuffer + offset + 0) = (u_theta_dot.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_theta_dot.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_theta_dot.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_theta_dot.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_theta_dot.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_theta_dot.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_theta_dot.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_theta_dot.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->theta_dot);
      union {
        double real;
        uint64_t base;
      } u_x_b_l_dot;
      u_x_b_l_dot.real = this->x_b_l_dot;
      *(outbuffer + offset + 0) = (u_x_b_l_dot.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x_b_l_dot.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x_b_l_dot.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x_b_l_dot.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_x_b_l_dot.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_x_b_l_dot.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_x_b_l_dot.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_x_b_l_dot.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x_b_l_dot);
      union {
        double real;
        uint64_t base;
      } u_x_b_r_dot;
      u_x_b_r_dot.real = this->x_b_r_dot;
      *(outbuffer + offset + 0) = (u_x_b_r_dot.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x_b_r_dot.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x_b_r_dot.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x_b_r_dot.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_x_b_r_dot.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_x_b_r_dot.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_x_b_r_dot.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_x_b_r_dot.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x_b_r_dot);
      union {
        double real;
        uint64_t base;
      } u_T_l;
      u_T_l.real = this->T_l;
      *(outbuffer + offset + 0) = (u_T_l.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_T_l.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_T_l.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_T_l.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_T_l.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_T_l.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_T_l.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_T_l.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->T_l);
      union {
        double real;
        uint64_t base;
      } u_T_r;
      u_T_r.real = this->T_r;
      *(outbuffer + offset + 0) = (u_T_r.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_T_r.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_T_r.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_T_r.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_T_r.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_T_r.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_T_r.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_T_r.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->T_r);
      union {
        double real;
        uint64_t base;
      } u_f_b_l;
      u_f_b_l.real = this->f_b_l;
      *(outbuffer + offset + 0) = (u_f_b_l.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_f_b_l.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_f_b_l.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_f_b_l.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_f_b_l.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_f_b_l.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_f_b_l.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_f_b_l.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->f_b_l);
      union {
        double real;
        uint64_t base;
      } u_f_b_r;
      u_f_b_r.real = this->f_b_r;
      *(outbuffer + offset + 0) = (u_f_b_r.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_f_b_r.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_f_b_r.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_f_b_r.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_f_b_r.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_f_b_r.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_f_b_r.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_f_b_r.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->f_b_r);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        double real;
        uint64_t base;
      } u_phi;
      u_phi.base = 0;
      u_phi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_phi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_phi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_phi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_phi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_phi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_phi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_phi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->phi = u_phi.real;
      offset += sizeof(this->phi);
      union {
        double real;
        uint64_t base;
      } u_theta;
      u_theta.base = 0;
      u_theta.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_theta.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_theta.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_theta.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_theta.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_theta.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_theta.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_theta.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->theta = u_theta.real;
      offset += sizeof(this->theta);
      union {
        double real;
        uint64_t base;
      } u_x_b_l;
      u_x_b_l.base = 0;
      u_x_b_l.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x_b_l.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x_b_l.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x_b_l.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_x_b_l.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_x_b_l.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_x_b_l.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_x_b_l.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->x_b_l = u_x_b_l.real;
      offset += sizeof(this->x_b_l);
      union {
        double real;
        uint64_t base;
      } u_x_b_r;
      u_x_b_r.base = 0;
      u_x_b_r.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x_b_r.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x_b_r.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x_b_r.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_x_b_r.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_x_b_r.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_x_b_r.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_x_b_r.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->x_b_r = u_x_b_r.real;
      offset += sizeof(this->x_b_r);
      union {
        double real;
        uint64_t base;
      } u_x_dot;
      u_x_dot.base = 0;
      u_x_dot.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x_dot.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x_dot.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x_dot.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_x_dot.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_x_dot.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_x_dot.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_x_dot.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->x_dot = u_x_dot.real;
      offset += sizeof(this->x_dot);
      union {
        double real;
        uint64_t base;
      } u_phi_dot;
      u_phi_dot.base = 0;
      u_phi_dot.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_phi_dot.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_phi_dot.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_phi_dot.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_phi_dot.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_phi_dot.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_phi_dot.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_phi_dot.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->phi_dot = u_phi_dot.real;
      offset += sizeof(this->phi_dot);
      union {
        double real;
        uint64_t base;
      } u_theta_dot;
      u_theta_dot.base = 0;
      u_theta_dot.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_theta_dot.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_theta_dot.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_theta_dot.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_theta_dot.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_theta_dot.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_theta_dot.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_theta_dot.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->theta_dot = u_theta_dot.real;
      offset += sizeof(this->theta_dot);
      union {
        double real;
        uint64_t base;
      } u_x_b_l_dot;
      u_x_b_l_dot.base = 0;
      u_x_b_l_dot.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x_b_l_dot.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x_b_l_dot.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x_b_l_dot.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_x_b_l_dot.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_x_b_l_dot.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_x_b_l_dot.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_x_b_l_dot.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->x_b_l_dot = u_x_b_l_dot.real;
      offset += sizeof(this->x_b_l_dot);
      union {
        double real;
        uint64_t base;
      } u_x_b_r_dot;
      u_x_b_r_dot.base = 0;
      u_x_b_r_dot.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x_b_r_dot.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x_b_r_dot.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x_b_r_dot.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_x_b_r_dot.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_x_b_r_dot.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_x_b_r_dot.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_x_b_r_dot.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->x_b_r_dot = u_x_b_r_dot.real;
      offset += sizeof(this->x_b_r_dot);
      union {
        double real;
        uint64_t base;
      } u_T_l;
      u_T_l.base = 0;
      u_T_l.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_T_l.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_T_l.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_T_l.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_T_l.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_T_l.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_T_l.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_T_l.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->T_l = u_T_l.real;
      offset += sizeof(this->T_l);
      union {
        double real;
        uint64_t base;
      } u_T_r;
      u_T_r.base = 0;
      u_T_r.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_T_r.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_T_r.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_T_r.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_T_r.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_T_r.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_T_r.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_T_r.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->T_r = u_T_r.real;
      offset += sizeof(this->T_r);
      union {
        double real;
        uint64_t base;
      } u_f_b_l;
      u_f_b_l.base = 0;
      u_f_b_l.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_f_b_l.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_f_b_l.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_f_b_l.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_f_b_l.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_f_b_l.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_f_b_l.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_f_b_l.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->f_b_l = u_f_b_l.real;
      offset += sizeof(this->f_b_l);
      union {
        double real;
        uint64_t base;
      } u_f_b_r;
      u_f_b_r.base = 0;
      u_f_b_r.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_f_b_r.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_f_b_r.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_f_b_r.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_f_b_r.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_f_b_r.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_f_b_r.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_f_b_r.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->f_b_r = u_f_b_r.real;
      offset += sizeof(this->f_b_r);
     return offset;
    }

    virtual const char * getType() override { return "rm_msgs/BalanceState"; };
    virtual const char * getMD5() override { return "1ad01479a611712f3c0679dc678d8b47"; };

  };

}
#endif
