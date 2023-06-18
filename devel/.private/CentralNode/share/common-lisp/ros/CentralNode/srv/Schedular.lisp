; Auto-generated. Do not edit!


(cl:in-package CentralNode-srv)


;//! \htmlinclude Schedular-request.msg.html

(cl:defclass <Schedular-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass Schedular-request (<Schedular-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Schedular-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Schedular-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name CentralNode-srv:<Schedular-request> is deprecated: use CentralNode-srv:Schedular-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Schedular-request>) ostream)
  "Serializes a message object of type '<Schedular-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Schedular-request>) istream)
  "Deserializes a message object of type '<Schedular-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Schedular-request>)))
  "Returns string type for a service object of type '<Schedular-request>"
  "CentralNode/SchedularRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Schedular-request)))
  "Returns string type for a service object of type 'Schedular-request"
  "CentralNode/SchedularRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Schedular-request>)))
  "Returns md5sum for a message object of type '<Schedular-request>"
  "ab7b1b43f5a75abfd5d43934103bc4a6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Schedular-request)))
  "Returns md5sum for a message object of type 'Schedular-request"
  "ab7b1b43f5a75abfd5d43934103bc4a6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Schedular-request>)))
  "Returns full string definition for message of type '<Schedular-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Schedular-request)))
  "Returns full string definition for message of type 'Schedular-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Schedular-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Schedular-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Schedular-request
))
;//! \htmlinclude Schedular-response.msg.html

(cl:defclass <Schedular-response> (roslisp-msg-protocol:ros-message)
  ((waypoints
    :reader waypoints
    :initarg :waypoints
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (waypoint_types
    :reader waypoint_types
    :initarg :waypoint_types
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass Schedular-response (<Schedular-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Schedular-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Schedular-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name CentralNode-srv:<Schedular-response> is deprecated: use CentralNode-srv:Schedular-response instead.")))

(cl:ensure-generic-function 'waypoints-val :lambda-list '(m))
(cl:defmethod waypoints-val ((m <Schedular-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader CentralNode-srv:waypoints-val is deprecated.  Use CentralNode-srv:waypoints instead.")
  (waypoints m))

(cl:ensure-generic-function 'waypoint_types-val :lambda-list '(m))
(cl:defmethod waypoint_types-val ((m <Schedular-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader CentralNode-srv:waypoint_types-val is deprecated.  Use CentralNode-srv:waypoint_types instead.")
  (waypoint_types m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Schedular-response>) ostream)
  "Serializes a message object of type '<Schedular-response>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'waypoints))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'waypoints))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'waypoint_types))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'waypoint_types))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Schedular-response>) istream)
  "Deserializes a message object of type '<Schedular-response>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'waypoints) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'waypoints)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'waypoint_types) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'waypoint_types)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296)))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Schedular-response>)))
  "Returns string type for a service object of type '<Schedular-response>"
  "CentralNode/SchedularResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Schedular-response)))
  "Returns string type for a service object of type 'Schedular-response"
  "CentralNode/SchedularResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Schedular-response>)))
  "Returns md5sum for a message object of type '<Schedular-response>"
  "ab7b1b43f5a75abfd5d43934103bc4a6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Schedular-response)))
  "Returns md5sum for a message object of type 'Schedular-response"
  "ab7b1b43f5a75abfd5d43934103bc4a6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Schedular-response>)))
  "Returns full string definition for message of type '<Schedular-response>"
  (cl:format cl:nil "float64[] waypoints ~%int32[] waypoint_types~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Schedular-response)))
  "Returns full string definition for message of type 'Schedular-response"
  (cl:format cl:nil "float64[] waypoints ~%int32[] waypoint_types~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Schedular-response>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'waypoints) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'waypoint_types) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Schedular-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Schedular-response
    (cl:cons ':waypoints (waypoints msg))
    (cl:cons ':waypoint_types (waypoint_types msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Schedular)))
  'Schedular-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Schedular)))
  'Schedular-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Schedular)))
  "Returns string type for a service object of type '<Schedular>"
  "CentralNode/Schedular")