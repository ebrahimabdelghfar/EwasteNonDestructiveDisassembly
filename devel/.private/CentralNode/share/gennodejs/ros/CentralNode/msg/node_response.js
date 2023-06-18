// Auto-generated. Do not edit!

// (in-package CentralNode.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class node_response {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.nodeId = null;
      this.extraMessage = null;
      this.status = null;
    }
    else {
      if (initObj.hasOwnProperty('nodeId')) {
        this.nodeId = initObj.nodeId
      }
      else {
        this.nodeId = 0;
      }
      if (initObj.hasOwnProperty('extraMessage')) {
        this.extraMessage = initObj.extraMessage
      }
      else {
        this.extraMessage = '';
      }
      if (initObj.hasOwnProperty('status')) {
        this.status = initObj.status
      }
      else {
        this.status = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type node_response
    // Serialize message field [nodeId]
    bufferOffset = _serializer.int32(obj.nodeId, buffer, bufferOffset);
    // Serialize message field [extraMessage]
    bufferOffset = _serializer.string(obj.extraMessage, buffer, bufferOffset);
    // Serialize message field [status]
    bufferOffset = _serializer.uint8(obj.status, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type node_response
    let len;
    let data = new node_response(null);
    // Deserialize message field [nodeId]
    data.nodeId = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [extraMessage]
    data.extraMessage = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [status]
    data.status = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.extraMessage);
    return length + 9;
  }

  static datatype() {
    // Returns string type for a message object
    return 'CentralNode/node_response';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b888e972b0112a456a30ae15a1f395cd';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 nodeId
    string extraMessage
    uint8 status
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new node_response(null);
    if (msg.nodeId !== undefined) {
      resolved.nodeId = msg.nodeId;
    }
    else {
      resolved.nodeId = 0
    }

    if (msg.extraMessage !== undefined) {
      resolved.extraMessage = msg.extraMessage;
    }
    else {
      resolved.extraMessage = ''
    }

    if (msg.status !== undefined) {
      resolved.status = msg.status;
    }
    else {
      resolved.status = 0
    }

    return resolved;
    }
};

module.exports = node_response;
