; Auto-generated. Do not edit!


(cl:in-package CentralNode-msg)


;//! \htmlinclude node_response.msg.html

(cl:defclass <node_response> (roslisp-msg-protocol:ros-message)
  ((nodeId
    :reader nodeId
    :initarg :nodeId
    :type cl:integer
    :initform 0)
   (extraMessage
    :reader extraMessage
    :initarg :extraMessage
    :type cl:string
    :initform "")
   (status
    :reader status
    :initarg :status
    :type cl:fixnum
    :initform 0))
)

(cl:defclass node_response (<node_response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <node_response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'node_response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name CentralNode-msg:<node_response> is deprecated: use CentralNode-msg:node_response instead.")))

(cl:ensure-generic-function 'nodeId-val :lambda-list '(m))
(cl:defmethod nodeId-val ((m <node_response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader CentralNode-msg:nodeId-val is deprecated.  Use CentralNode-msg:nodeId instead.")
  (nodeId m))

(cl:ensure-generic-function 'extraMessage-val :lambda-list '(m))
(cl:defmethod extraMessage-val ((m <node_response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader CentralNode-msg:extraMessage-val is deprecated.  Use CentralNode-msg:extraMessage instead.")
  (extraMessage m))

(cl:ensure-generic-function 'status-val :lambda-list '(m))
(cl:defmethod status-val ((m <node_response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader CentralNode-msg:status-val is deprecated.  Use CentralNode-msg:status instead.")
  (status m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <node_response>) ostream)
  "Serializes a message object of type '<node_response>"
  (cl:let* ((signed (cl:slot-value msg 'nodeId)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'extraMessage))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'extraMessage))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'status)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <node_response>) istream)
  "Deserializes a message object of type '<node_response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'nodeId) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'extraMessage) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'extraMessage) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'status)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<node_response>)))
  "Returns string type for a message object of type '<node_response>"
  "CentralNode/node_response")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'node_response)))
  "Returns string type for a message object of type 'node_response"
  "CentralNode/node_response")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<node_response>)))
  "Returns md5sum for a message object of type '<node_response>"
  "b888e972b0112a456a30ae15a1f395cd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'node_response)))
  "Returns md5sum for a message object of type 'node_response"
  "b888e972b0112a456a30ae15a1f395cd")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<node_response>)))
  "Returns full string definition for message of type '<node_response>"
  (cl:format cl:nil "int32 nodeId~%string extraMessage~%uint8 status~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'node_response)))
  "Returns full string definition for message of type 'node_response"
  (cl:format cl:nil "int32 nodeId~%string extraMessage~%uint8 status~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <node_response>))
  (cl:+ 0
     4
     4 (cl:length (cl:slot-value msg 'extraMessage))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <node_response>))
  "Converts a ROS message object to a list"
  (cl:list 'node_response
    (cl:cons ':nodeId (nodeId msg))
    (cl:cons ':extraMessage (extraMessage msg))
    (cl:cons ':status (status msg))
))
