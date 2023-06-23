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
  :slots (_waypoints _waypoint_types _checkTorque _velocity _acceleration ))

(defmethod CentralNode::SchedularResponse
  (:init
   (&key
    ((:waypoints __waypoints) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:waypoint_types __waypoint_types) (make-array 0 :initial-element 0 :element-type :integer))
    ((:checkTorque __checkTorque) (make-array 0 :initial-element 0 :element-type :integer))
    ((:velocity __velocity) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:acceleration __acceleration) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _waypoints __waypoints)
   (setq _waypoint_types __waypoint_types)
   (setq _checkTorque __checkTorque)
   (setq _velocity __velocity)
   (setq _acceleration __acceleration)
   self)
  (:waypoints
   (&optional __waypoints)
   (if __waypoints (setq _waypoints __waypoints)) _waypoints)
  (:waypoint_types
   (&optional __waypoint_types)
   (if __waypoint_types (setq _waypoint_types __waypoint_types)) _waypoint_types)
  (:checkTorque
   (&optional __checkTorque)
   (if __checkTorque (setq _checkTorque __checkTorque)) _checkTorque)
  (:velocity
   (&optional __velocity)
   (if __velocity (setq _velocity __velocity)) _velocity)
  (:acceleration
   (&optional __acceleration)
   (if __acceleration (setq _acceleration __acceleration)) _acceleration)
  (:serialization-length
   ()
   (+
    ;; float64[] _waypoints
    (* 8    (length _waypoints)) 4
    ;; int32[] _waypoint_types
    (* 4    (length _waypoint_types)) 4
    ;; int32[] _checkTorque
    (* 4    (length _checkTorque)) 4
    ;; float64[] _velocity
    (* 8    (length _velocity)) 4
    ;; float64[] _acceleration
    (* 8    (length _acceleration)) 4
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
     ;; int32[] _checkTorque
     (write-long (length _checkTorque) s)
     (dotimes (i (length _checkTorque))
       (write-long (elt _checkTorque i) s)
       )
     ;; float64[] _velocity
     (write-long (length _velocity) s)
     (dotimes (i (length _velocity))
       (sys::poke (elt _velocity i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _acceleration
     (write-long (length _acceleration) s)
     (dotimes (i (length _acceleration))
       (sys::poke (elt _acceleration i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
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
   ;; int32[] _checkTorque
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _checkTorque (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _checkTorque i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; float64[] _velocity
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _velocity (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _velocity i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _acceleration
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _acceleration (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _acceleration i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(defclass CentralNode::Schedular
  :super ros::object
  :slots ())

(setf (get CentralNode::Schedular :md5sum-) "d637c22bbf3cb0d5961d15592eaa346e")
(setf (get CentralNode::Schedular :datatype-) "CentralNode/Schedular")
(setf (get CentralNode::Schedular :request) CentralNode::SchedularRequest)
(setf (get CentralNode::Schedular :response) CentralNode::SchedularResponse)

(defmethod CentralNode::SchedularRequest
  (:response () (instance CentralNode::SchedularResponse :init)))

(setf (get CentralNode::SchedularRequest :md5sum-) "d637c22bbf3cb0d5961d15592eaa346e")
(setf (get CentralNode::SchedularRequest :datatype-) "CentralNode/SchedularRequest")
(setf (get CentralNode::SchedularRequest :definition-)
      "---
float64[] waypoints 
int32[] waypoint_types
int32[] checkTorque
float64[] velocity
float64[] acceleration 
")

(setf (get CentralNode::SchedularResponse :md5sum-) "d637c22bbf3cb0d5961d15592eaa346e")
(setf (get CentralNode::SchedularResponse :datatype-) "CentralNode/SchedularResponse")
(setf (get CentralNode::SchedularResponse :definition-)
      "---
float64[] waypoints 
int32[] waypoint_types
int32[] checkTorque
float64[] velocity
float64[] acceleration 
")



(provide :CentralNode/Schedular "d637c22bbf3cb0d5961d15592eaa346e")


