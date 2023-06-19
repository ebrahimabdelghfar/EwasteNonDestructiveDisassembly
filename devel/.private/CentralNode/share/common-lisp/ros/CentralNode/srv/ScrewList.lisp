; Auto-generated. Do not edit!


(cl:in-package CentralNode-srv)


;//! \htmlinclude ScrewList-request.msg.html

(cl:defclass <ScrewList-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass ScrewList-request (<ScrewList-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ScrewList-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ScrewList-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name CentralNode-srv:<ScrewList-request> is deprecated: use CentralNode-srv:ScrewList-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ScrewList-request>) ostream)
  "Serializes a message object of type '<ScrewList-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ScrewList-request>) istream)
  "Deserializes a message object of type '<ScrewList-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ScrewList-request>)))
  "Returns string type for a service object of type '<ScrewList-request>"
  "CentralNode/ScrewListRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ScrewList-request)))
  "Returns string type for a service object of type 'ScrewList-request"
  "CentralNode/ScrewListRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ScrewList-request>)))
  "Returns md5sum for a message object of type '<ScrewList-request>"
  "2f6d262f128183ca8a94edda08422d99")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ScrewList-request)))
  "Returns md5sum for a message object of type 'ScrewList-request"
  "2f6d262f128183ca8a94edda08422d99")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ScrewList-request>)))
  "Returns full string definition for message of type '<ScrewList-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ScrewList-request)))
  "Returns full string definition for message of type 'ScrewList-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ScrewList-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ScrewList-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ScrewList-request
))
;//! \htmlinclude ScrewList-response.msg.html

(cl:defclass <ScrewList-response> (roslisp-msg-protocol:ros-message)
  ((screwList
    :reader screwList
    :initarg :screwList
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass ScrewList-response (<ScrewList-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ScrewList-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ScrewList-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name CentralNode-srv:<ScrewList-response> is deprecated: use CentralNode-srv:ScrewList-response instead.")))

(cl:ensure-generic-function 'screwList-val :lambda-list '(m))
(cl:defmethod screwList-val ((m <ScrewList-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader CentralNode-srv:screwList-val is deprecated.  Use CentralNode-srv:screwList instead.")
  (screwList m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ScrewList-response>) ostream)
  "Serializes a message object of type '<ScrewList-response>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'screwList))))
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
   (cl:slot-value msg 'screwList))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ScrewList-response>) istream)
  "Deserializes a message object of type '<ScrewList-response>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'screwList) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'screwList)))
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
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ScrewList-response>)))
  "Returns string type for a service object of type '<ScrewList-response>"
  "CentralNode/ScrewListResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ScrewList-response)))
  "Returns string type for a service object of type 'ScrewList-response"
  "CentralNode/ScrewListResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ScrewList-response>)))
  "Returns md5sum for a message object of type '<ScrewList-response>"
  "2f6d262f128183ca8a94edda08422d99")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ScrewList-response)))
  "Returns md5sum for a message object of type 'ScrewList-response"
  "2f6d262f128183ca8a94edda08422d99")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ScrewList-response>)))
  "Returns full string definition for message of type '<ScrewList-response>"
  (cl:format cl:nil "float64[] screwList~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ScrewList-response)))
  "Returns full string definition for message of type 'ScrewList-response"
  (cl:format cl:nil "float64[] screwList~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ScrewList-response>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'screwList) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ScrewList-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ScrewList-response
    (cl:cons ':screwList (screwList msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ScrewList)))
  'ScrewList-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ScrewList)))
  'ScrewList-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ScrewList)))
  "Returns string type for a service object of type '<ScrewList>"
  "CentralNode/ScrewList")