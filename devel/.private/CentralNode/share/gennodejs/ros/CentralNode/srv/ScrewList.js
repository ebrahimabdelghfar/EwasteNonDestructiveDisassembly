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

class ScrewListRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
    }
    else {
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ScrewListRequest
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ScrewListRequest
    let len;
    let data = new ScrewListRequest(null);
    return data;
  }

  static getMessageSize(object) {
    return 0;
  }

  static datatype() {
    // Returns string type for a service object
    return 'CentralNode/ScrewListRequest';
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
    const resolved = new ScrewListRequest(null);
    return resolved;
    }
};

class ScrewListResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.screwList = null;
    }
    else {
      if (initObj.hasOwnProperty('screwList')) {
        this.screwList = initObj.screwList
      }
      else {
        this.screwList = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ScrewListResponse
    // Serialize message field [screwList]
    bufferOffset = _arraySerializer.float64(obj.screwList, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ScrewListResponse
    let len;
    let data = new ScrewListResponse(null);
    // Deserialize message field [screwList]
    data.screwList = _arrayDeserializer.float64(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 8 * object.screwList.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'CentralNode/ScrewListResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2f6d262f128183ca8a94edda08422d99';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64[] screwList
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ScrewListResponse(null);
    if (msg.screwList !== undefined) {
      resolved.screwList = msg.screwList;
    }
    else {
      resolved.screwList = []
    }

    return resolved;
    }
};

module.exports = {
  Request: ScrewListRequest,
  Response: ScrewListResponse,
  md5sum() { return '2f6d262f128183ca8a94edda08422d99'; },
  datatype() { return 'CentralNode/ScrewList'; }
};
