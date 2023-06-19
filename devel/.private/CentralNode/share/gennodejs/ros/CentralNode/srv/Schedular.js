// Auto-generated. Do not edit!

// (in-package CentralNode.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class SchedularRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
    }
    else {
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SchedularRequest
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SchedularRequest
    let len;
    let data = new SchedularRequest(null);
    return data;
  }

  static getMessageSize(object) {
    return 0;
  }

  static datatype() {
    // Returns string type for a service object
    return 'CentralNode/SchedularRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd41d8cd98f00b204e9800998ecf8427e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SchedularRequest(null);
    return resolved;
    }
};

class SchedularResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.waypoints = null;
      this.waypoint_types = null;
      this.checkTorque = null;
      this.velocity = null;
      this.acceleration = null;
    }
    else {
      if (initObj.hasOwnProperty('waypoints')) {
        this.waypoints = initObj.waypoints
      }
      else {
        this.waypoints = [];
      }
      if (initObj.hasOwnProperty('waypoint_types')) {
        this.waypoint_types = initObj.waypoint_types
      }
      else {
        this.waypoint_types = [];
      }
      if (initObj.hasOwnProperty('checkTorque')) {
        this.checkTorque = initObj.checkTorque
      }
      else {
        this.checkTorque = [];
      }
      if (initObj.hasOwnProperty('velocity')) {
        this.velocity = initObj.velocity
      }
      else {
        this.velocity = [];
      }
      if (initObj.hasOwnProperty('acceleration')) {
        this.acceleration = initObj.acceleration
      }
      else {
        this.acceleration = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SchedularResponse
    // Serialize message field [waypoints]
    bufferOffset = _arraySerializer.float64(obj.waypoints, buffer, bufferOffset, null);
    // Serialize message field [waypoint_types]
    bufferOffset = _arraySerializer.int32(obj.waypoint_types, buffer, bufferOffset, null);
    // Serialize message field [checkTorque]
    bufferOffset = _arraySerializer.int32(obj.checkTorque, buffer, bufferOffset, null);
    // Serialize message field [velocity]
    bufferOffset = _arraySerializer.float64(obj.velocity, buffer, bufferOffset, null);
    // Serialize message field [acceleration]
    bufferOffset = _arraySerializer.float64(obj.acceleration, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SchedularResponse
    let len;
    let data = new SchedularResponse(null);
    // Deserialize message field [waypoints]
    data.waypoints = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [waypoint_types]
    data.waypoint_types = _arrayDeserializer.int32(buffer, bufferOffset, null)
    // Deserialize message field [checkTorque]
    data.checkTorque = _arrayDeserializer.int32(buffer, bufferOffset, null)
    // Deserialize message field [velocity]
    data.velocity = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [acceleration]
    data.acceleration = _arrayDeserializer.float64(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 8 * object.waypoints.length;
    length += 4 * object.waypoint_types.length;
    length += 4 * object.checkTorque.length;
    length += 8 * object.velocity.length;
    length += 8 * object.acceleration.length;
    return length + 20;
  }

  static datatype() {
    // Returns string type for a service object
    return 'CentralNode/SchedularResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd637c22bbf3cb0d5961d15592eaa346e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64[] waypoints 
    int32[] waypoint_types
    int32[] checkTorque
    float64[] velocity
    float64[] acceleration 
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SchedularResponse(null);
    if (msg.waypoints !== undefined) {
      resolved.waypoints = msg.waypoints;
    }
    else {
      resolved.waypoints = []
    }

    if (msg.waypoint_types !== undefined) {
      resolved.waypoint_types = msg.waypoint_types;
    }
    else {
      resolved.waypoint_types = []
    }

    if (msg.checkTorque !== undefined) {
      resolved.checkTorque = msg.checkTorque;
    }
    else {
      resolved.checkTorque = []
    }

    if (msg.velocity !== undefined) {
      resolved.velocity = msg.velocity;
    }
    else {
      resolved.velocity = []
    }

    if (msg.acceleration !== undefined) {
      resolved.acceleration = msg.acceleration;
    }
    else {
      resolved.acceleration = []
    }

    return resolved;
    }
};

module.exports = {
  Request: SchedularRequest,
  Response: SchedularResponse,
  md5sum() { return 'd637c22bbf3cb0d5961d15592eaa346e'; },
  datatype() { return 'CentralNode/Schedular'; }
};
