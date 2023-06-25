;; Auto-generated. Do not edit!


(when (boundp 'CentralNode::Schedular)
  (if (not (find-package "CENTRALNODE"))
    (make-package "CENTRALNODE"))
  (shadow 'Schedular (find-package "CENTRALNODE")))
(unless (find-package "CENTRALNODE::SCHEDULAR")
  (make-package "CENTRALNODE::SCHEDULAR"))
(unless (find-package "CENTRALNODE::SCHEDULARREQUEST")
  (make-package "CENTRALNODE::SCHEDULARREQUEST"))
(unless (find-package "CENTRALNODE::SCHEDULARRESPONSE")
  (make-package "CENTRALNODE::SCHEDULARRESPONSE"))

(in-package "ROS")





(defclass CentralNode::SchedularRequest
  :super ros::object
  :slots ())

(defmethod CentralNode::SchedularRequest
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass CentralNode::SchedularResponse
  :super ros::object
  :slots (_waypoints _waypoint_types ))

(defmethod CentralNode::SchedularResponse
  (:init
   (&key
    ((:waypoints __waypoints) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:waypoint_types __waypoint_types) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _waypoints __waypoints)
   (setq _waypoint_types __waypoint_types)
   self)
  (:waypoints
   (&optional __waypoints)
   (if __waypoints (setq _waypoints __waypoints)) _waypoints)
  (:waypoint_types
   (&optional __waypoint_types)
   (if __waypoint_types (setq _waypoint_types __waypoint_types)) _waypoint_types)
  (:serialization-length
   ()
   (+
    ;; float64[] _waypoints
    (* 8    (length _waypoints)) 4
    ;; int32[] _waypoint_types
    (* 4    (length _waypoint_types)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64[] _waypoints
     (write-long (length _waypoints) s)
     (dotimes (i (length _waypoints))
       (sys::poke (elt _waypoints i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; int32[] _waypoint_types
     (write-long (length _waypoint_types) s)
     (dotimes (i (length _waypoint_types))
       (write-long (elt _waypoint_types i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64[] _waypoints
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _waypoints (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _waypoints i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; int32[] _waypoint_types
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _waypoint_types (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _waypoint_types i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(defclass CentralNode::Schedular
  :super ros::object
  :slots ())

(setf (get CentralNode::Schedular :md5sum-) "ab7b1b43f5a75abfd5d43934103bc4a6")
(setf (get CentralNode::Schedular :datatype-) "CentralNode/Schedular")
(setf (get CentralNode::Schedular :request) CentralNode::SchedularRequest)
(setf (get CentralNode::Schedular :response) CentralNode::SchedularResponse)

(defmethod CentralNode::SchedularRequest
  (:response () (instance CentralNode::SchedularResponse :init)))

(setf (get CentralNode::SchedularRequest :md5sum-) "ab7b1b43f5a75abfd5d43934103bc4a6")
(setf (get CentralNode::SchedularRequest :datatype-) "CentralNode/SchedularRequest")
(setf (get CentralNode::SchedularRequest :definition-)
      "---
float64[] waypoints 
int32[] waypoint_types
")

(setf (get CentralNode::SchedularResponse :md5sum-) "ab7b1b43f5a75abfd5d43934103bc4a6")
(setf (get CentralNode::SchedularResponse :datatype-) "CentralNode/SchedularResponse")
(setf (get CentralNode::SchedularResponse :definition-)
      "---
float64[] waypoints 
int32[] waypoint_types
")



(provide :CentralNode/Schedular "ab7b1b43f5a75abfd5d43934103bc4a6")


