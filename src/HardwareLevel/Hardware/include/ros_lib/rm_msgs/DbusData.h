#ifndef _ROS_rm_msgs_DbusData_h
#define _ROS_rm_msgs_DbusData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace rm_msgs
{

  class DbusData : public ros::Msg
  {
    public:
      typedef double _ch_l_x_type;
      _ch_l_x_type ch_l_x;
      typedef double _ch_l_y_type;
      _ch_l_y_type ch_l_y;
      typedef double _ch_r_x_type;
      _ch_r_x_type ch_r_x;
      typedef double _ch_r_y_type;
      _ch_r_y_type ch_r_y;
      typedef uint8_t _s_l_type;
      _s_l_type s_l;
      typedef uint8_t _s_r_type;
      _s_r_type s_r;
      typedef double _wheel_type;
      _wheel_type wheel;
      typedef double _m_x_type;
      _m_x_type m_x;
      typedef double _m_y_type;
      _m_y_type m_y;
      typedef double _m_z_type;
      _m_z_type m_z;
      typedef bool _p_l_type;
      _p_l_type p_l;
      typedef bool _p_r_type;
      _p_r_type p_r;
      typedef bool _key_w_type;
      _key_w_type key_w;
      typedef bool _key_s_type;
      _key_s_type key_s;
      typedef bool _key_a_type;
      _key_a_type key_a;
      typedef bool _key_d_type;
      _key_d_type key_d;
      typedef bool _key_shift_type;
      _key_shift_type key_shift;
      typedef bool _key_ctrl_type;
      _key_ctrl_type key_ctrl;
      typedef bool _key_q_type;
      _key_q_type key_q;
      typedef bool _key_e_type;
      _key_e_type key_e;
      typedef bool _key_r_type;
      _key_r_type key_r;
      typedef bool _key_f_type;
      _key_f_type key_f;
      typedef bool _key_g_type;
      _key_g_type key_g;
      typedef bool _key_z_type;
      _key_z_type key_z;
      typedef bool _key_x_type;
      _key_x_type key_x;
      typedef bool _key_c_type;
      _key_c_type key_c;
      typedef bool _key_v_type;
      _key_v_type key_v;
      typedef bool _key_b_type;
      _key_b_type key_b;
      typedef ros::Time _stamp_type;
      _stamp_type stamp;
      enum { UP =  1 };
      enum { DOWN =  2 };
      enum { MID =  3 };

    DbusData():
      ch_l_x(0),
      ch_l_y(0),
      ch_r_x(0),
      ch_r_y(0),
      s_l(0),
      s_r(0),
      wheel(0),
      m_x(0),
      m_y(0),
      m_z(0),
      p_l(0),
      p_r(0),
      key_w(0),
      key_s(0),
      key_a(0),
      key_d(0),
      key_shift(0),
      key_ctrl(0),
      key_q(0),
      key_e(0),
      key_r(0),
      key_f(0),
      key_g(0),
      key_z(0),
      key_x(0),
      key_c(0),
      key_v(0),
      key_b(0),
      stamp()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_ch_l_x;
      u_ch_l_x.real = this->ch_l_x;
      *(outbuffer + offset + 0) = (u_ch_l_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ch_l_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ch_l_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ch_l_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ch_l_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ch_l_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ch_l_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ch_l_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ch_l_x);
      union {
        double real;
        uint64_t base;
      } u_ch_l_y;
      u_ch_l_y.real = this->ch_l_y;
      *(outbuffer + offset + 0) = (u_ch_l_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ch_l_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ch_l_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ch_l_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ch_l_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ch_l_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ch_l_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ch_l_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ch_l_y);
      union {
        double real;
        uint64_t base;
      } u_ch_r_x;
      u_ch_r_x.real = this->ch_r_x;
      *(outbuffer + offset + 0) = (u_ch_r_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ch_r_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ch_r_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ch_r_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ch_r_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ch_r_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ch_r_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ch_r_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ch_r_x);
      union {
        double real;
        uint64_t base;
      } u_ch_r_y;
      u_ch_r_y.real = this->ch_r_y;
      *(outbuffer + offset + 0) = (u_ch_r_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ch_r_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ch_r_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ch_r_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ch_r_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ch_r_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ch_r_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ch_r_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ch_r_y);
      *(outbuffer + offset + 0) = (this->s_l >> (8 * 0)) & 0xFF;
      offset += sizeof(this->s_l);
      *(outbuffer + offset + 0) = (this->s_r >> (8 * 0)) & 0xFF;
      offset += sizeof(this->s_r);
      union {
        double real;
        uint64_t base;
      } u_wheel;
      u_wheel.real = this->wheel;
      *(outbuffer + offset + 0) = (u_wheel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_wheel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_wheel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_wheel.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_wheel.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_wheel.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_wheel.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_wheel.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->wheel);
      union {
        double real;
        uint64_t base;
      } u_m_x;
      u_m_x.real = this->m_x;
      *(outbuffer + offset + 0) = (u_m_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_m_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_m_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_m_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_m_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_m_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_m_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_m_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->m_x);
      union {
        double real;
        uint64_t base;
      } u_m_y;
      u_m_y.real = this->m_y;
      *(outbuffer + offset + 0) = (u_m_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_m_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_m_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_m_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_m_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_m_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_m_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_m_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->m_y);
      union {
        double real;
        uint64_t base;
      } u_m_z;
      u_m_z.real = this->m_z;
      *(outbuffer + offset + 0) = (u_m_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_m_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_m_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_m_z.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_m_z.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_m_z.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_m_z.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_m_z.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->m_z);
      union {
        bool real;
        uint8_t base;
      } u_p_l;
      u_p_l.real = this->p_l;
      *(outbuffer + offset + 0) = (u_p_l.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->p_l);
      union {
        bool real;
        uint8_t base;
      } u_p_r;
      u_p_r.real = this->p_r;
      *(outbuffer + offset + 0) = (u_p_r.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->p_r);
      union {
        bool real;
        uint8_t base;
      } u_key_w;
      u_key_w.real = this->key_w;
      *(outbuffer + offset + 0) = (u_key_w.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->key_w);
      union {
        bool real;
        uint8_t base;
      } u_key_s;
      u_key_s.real = this->key_s;
      *(outbuffer + offset + 0) = (u_key_s.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->key_s);
      union {
        bool real;
        uint8_t base;
      } u_key_a;
      u_key_a.real = this->key_a;
      *(outbuffer + offset + 0) = (u_key_a.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->key_a);
      union {
        bool real;
        uint8_t base;
      } u_key_d;
      u_key_d.real = this->key_d;
      *(outbuffer + offset + 0) = (u_key_d.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->key_d);
      union {
        bool real;
        uint8_t base;
      } u_key_shift;
      u_key_shift.real = this->key_shift;
      *(outbuffer + offset + 0) = (u_key_shift.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->key_shift);
      union {
        bool real;
        uint8_t base;
      } u_key_ctrl;
      u_key_ctrl.real = this->key_ctrl;
      *(outbuffer + offset + 0) = (u_key_ctrl.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->key_ctrl);
      union {
        bool real;
        uint8_t base;
      } u_key_q;
      u_key_q.real = this->key_q;
      *(outbuffer + offset + 0) = (u_key_q.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->key_q);
      union {
        bool real;
        uint8_t base;
      } u_key_e;
      u_key_e.real = this->key_e;
      *(outbuffer + offset + 0) = (u_key_e.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->key_e);
      union {
        bool real;
        uint8_t base;
      } u_key_r;
      u_key_r.real = this->key_r;
      *(outbuffer + offset + 0) = (u_key_r.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->key_r);
      union {
        bool real;
        uint8_t base;
      } u_key_f;
      u_key_f.real = this->key_f;
      *(outbuffer + offset + 0) = (u_key_f.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->key_f);
      union {
        bool real;
        uint8_t base;
      } u_key_g;
      u_key_g.real = this->key_g;
      *(outbuffer + offset + 0) = (u_key_g.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->key_g);
      union {
        bool real;
        uint8_t base;
      } u_key_z;
      u_key_z.real = this->key_z;
      *(outbuffer + offset + 0) = (u_key_z.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->key_z);
      union {
        bool real;
        uint8_t base;
      } u_key_x;
      u_key_x.real = this->key_x;
      *(outbuffer + offset + 0) = (u_key_x.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->key_x);
      union {
        bool real;
        uint8_t base;
      } u_key_c;
      u_key_c.real = this->key_c;
      *(outbuffer + offset + 0) = (u_key_c.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->key_c);
      union {
        bool real;
        uint8_t base;
      } u_key_v;
      u_key_v.real = this->key_v;
      *(outbuffer + offset + 0) = (u_key_v.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->key_v);
      union {
        bool real;
        uint8_t base;
      } u_key_b;
      u_key_b.real = this->key_b;
      *(outbuffer + offset + 0) = (u_key_b.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->key_b);
      *(outbuffer + offset + 0) = (this->stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.sec);
      *(outbuffer + offset + 0) = (this->stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_ch_l_x;
      u_ch_l_x.base = 0;
      u_ch_l_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ch_l_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ch_l_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ch_l_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ch_l_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ch_l_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ch_l_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ch_l_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ch_l_x = u_ch_l_x.real;
      offset += sizeof(this->ch_l_x);
      union {
        double real;
        uint64_t base;
      } u_ch_l_y;
      u_ch_l_y.base = 0;
      u_ch_l_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ch_l_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ch_l_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ch_l_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ch_l_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ch_l_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ch_l_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ch_l_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ch_l_y = u_ch_l_y.real;
      offset += sizeof(this->ch_l_y);
      union {
        double real;
        uint64_t base;
      } u_ch_r_x;
      u_ch_r_x.base = 0;
      u_ch_r_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ch_r_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ch_r_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ch_r_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ch_r_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ch_r_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ch_r_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ch_r_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ch_r_x = u_ch_r_x.real;
      offset += sizeof(this->ch_r_x);
      union {
        double real;
        uint64_t base;
      } u_ch_r_y;
      u_ch_r_y.base = 0;
      u_ch_r_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ch_r_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ch_r_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ch_r_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ch_r_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ch_r_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ch_r_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ch_r_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ch_r_y = u_ch_r_y.real;
      offset += sizeof(this->ch_r_y);
      this->s_l =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->s_l);
      this->s_r =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->s_r);
      union {
        double real;
        uint64_t base;
      } u_wheel;
      u_wheel.base = 0;
      u_wheel.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_wheel.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_wheel.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_wheel.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_wheel.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_wheel.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_wheel.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_wheel.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->wheel = u_wheel.real;
      offset += sizeof(this->wheel);
      union {
        double real;
        uint64_t base;
      } u_m_x;
      u_m_x.base = 0;
      u_m_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_m_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_m_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_m_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_m_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_m_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_m_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_m_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->m_x = u_m_x.real;
      offset += sizeof(this->m_x);
      union {
        double real;
        uint64_t base;
      } u_m_y;
      u_m_y.base = 0;
      u_m_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_m_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_m_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_m_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_m_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_m_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_m_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_m_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->m_y = u_m_y.real;
      offset += sizeof(this->m_y);
      union {
        double real;
        uint64_t base;
      } u_m_z;
      u_m_z.base = 0;
      u_m_z.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_m_z.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_m_z.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_m_z.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_m_z.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_m_z.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_m_z.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_m_z.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->m_z = u_m_z.real;
      offset += sizeof(this->m_z);
      union {
        bool real;
        uint8_t base;
      } u_p_l;
      u_p_l.base = 0;
      u_p_l.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->p_l = u_p_l.real;
      offset += sizeof(this->p_l);
      union {
        bool real;
        uint8_t base;
      } u_p_r;
      u_p_r.base = 0;
      u_p_r.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->p_r = u_p_r.real;
      offset += sizeof(this->p_r);
      union {
        bool real;
        uint8_t base;
      } u_key_w;
      u_key_w.base = 0;
      u_key_w.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->key_w = u_key_w.real;
      offset += sizeof(this->key_w);
      union {
        bool real;
        uint8_t base;
      } u_key_s;
      u_key_s.base = 0;
      u_key_s.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->key_s = u_key_s.real;
      offset += sizeof(this->key_s);
      union {
        bool real;
        uint8_t base;
      } u_key_a;
      u_key_a.base = 0;
      u_key_a.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->key_a = u_key_a.real;
      offset += sizeof(this->key_a);
      union {
        bool real;
        uint8_t base;
      } u_key_d;
      u_key_d.base = 0;
      u_key_d.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->key_d = u_key_d.real;
      offset += sizeof(this->key_d);
      union {
        bool real;
        uint8_t base;
      } u_key_shift;
      u_key_shift.base = 0;
      u_key_shift.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->key_shift = u_key_shift.real;
      offset += sizeof(this->key_shift);
      union {
        bool real;
        uint8_t base;
      } u_key_ctrl;
      u_key_ctrl.base = 0;
      u_key_ctrl.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->key_ctrl = u_key_ctrl.real;
      offset += sizeof(this->key_ctrl);
      union {
        bool real;
        uint8_t base;
      } u_key_q;
      u_key_q.base = 0;
      u_key_q.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->key_q = u_key_q.real;
      offset += sizeof(this->key_q);
      union {
        bool real;
        uint8_t base;
      } u_key_e;
      u_key_e.base = 0;
      u_key_e.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->key_e = u_key_e.real;
      offset += sizeof(this->key_e);
      union {
        bool real;
        uint8_t base;
      } u_key_r;
      u_key_r.base = 0;
      u_key_r.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->key_r = u_key_r.real;
      offset += sizeof(this->key_r);
      union {
        bool real;
        uint8_t base;
      } u_key_f;
      u_key_f.base = 0;
      u_key_f.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->key_f = u_key_f.real;
      offset += sizeof(this->key_f);
      union {
        bool real;
        uint8_t base;
      } u_key_g;
      u_key_g.base = 0;
      u_key_g.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->key_g = u_key_g.real;
      offset += sizeof(this->key_g);
      union {
        bool real;
        uint8_t base;
      } u_key_z;
      u_key_z.base = 0;
      u_key_z.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->key_z = u_key_z.real;
      offset += sizeof(this->key_z);
      union {
        bool real;
        uint8_t base;
      } u_key_x;
      u_key_x.base = 0;
      u_key_x.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->key_x = u_key_x.real;
      offset += sizeof(this->key_x);
      union {
        bool real;
        uint8_t base;
      } u_key_c;
      u_key_c.base = 0;
      u_key_c.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->key_c = u_key_c.real;
      offset += sizeof(this->key_c);
      union {
        bool real;
        uint8_t base;
      } u_key_v;
      u_key_v.base = 0;
      u_key_v.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->key_v = u_key_v.real;
      offset += sizeof(this->key_v);
      union {
        bool real;
        uint8_t base;
      } u_key_b;
      u_key_b.base = 0;
      u_key_b.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->key_b = u_key_b.real;
      offset += sizeof(this->key_b);
      this->stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.sec);
      this->stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.nsec);
     return offset;
    }

    virtual const char * getType() override { return "rm_msgs/DbusData"; };
    virtual const char * getMD5() override { return "0220a682827f4bc1471e95e351489508"; };

  };

}
#endif
