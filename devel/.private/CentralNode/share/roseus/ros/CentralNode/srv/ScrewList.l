;; Auto-generated. Do not edit!


(when (boundp 'CentralNode::ScrewList)
  (if (not (find-package "CENTRALNODE"))
    (make-package "CENTRALNODE"))
  (shadow 'ScrewList (find-package "CENTRALNODE")))
(unless (find-package "CENTRALNODE::SCREWLIST")
  (make-package "CENTRALNODE::SCREWLIST"))
(unless (find-package "CENTRALNODE::SCREWLISTREQUEST")
  (make-package "CENTRALNODE::SCREWLISTREQUEST"))
(unless (find-package "CENTRALNODE::SCREWLISTRESPONSE")
  (make-package "CENTRALNODE::SCREWLISTRESPONSE"))

(in-package "ROS")





(defclass CentralNode::ScrewListRequest
  :super ros::object
  :slots ())

(defmethod CentralNode::ScrewListRequest
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

(defclass CentralNode::ScrewListResponse
  :super ros::object
  :slots (_screwList ))

(defmethod CentralNode::ScrewListResponse
  (:init
   (&key
    ((:screwList __screwList) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _screwList __screwList)
   self)
  (:screwList
   (&optional __screwList)
   (if __screwList (setq _screwList __screwList)) _screwList)
  (:serialization-length
   ()
   (+
    ;; float64[] _screwList
    (* 8    (length _screwList)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64[] _screwList
     (write-long (length _screwList) s)
     (dotimes (i (length _screwList))
       (sys::poke (elt _screwList i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64[] _screwList
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _screwList (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _screwList i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(defclass CentralNode::ScrewList
  :super ros::object
  :slots ())

(setf (get CentralNode::ScrewList :md5sum-) "2f6d262f128183ca8a94edda08422d99")
(setf (get CentralNode::ScrewList :datatype-) "CentralNode/ScrewList")
(setf (get CentralNode::ScrewList :request) CentralNode::ScrewListRequest)
(setf (get CentralNode::ScrewList :response) CentralNode::ScrewListResponse)

(defmethod CentralNode::ScrewListRequest
  (:response () (instance CentralNode::ScrewListResponse :init)))

(setf (get CentralNode::ScrewListRequest :md5sum-) "2f6d262f128183ca8a94edda08422d99")
(setf (get CentralNode::ScrewListRequest :datatype-) "CentralNode/ScrewListRequest")
(setf (get CentralNode::ScrewListRequest :definition-)
      "---
float64[] screwList
")

(setf (get CentralNode::ScrewListResponse :md5sum-) "2f6d262f128183ca8a94edda08422d99")
(setf (get CentralNode::ScrewListResponse :datatype-) "CentralNode/ScrewListResponse")
(setf (get CentralNode::ScrewListResponse :definition-)
      "---
float64[] screwList
")



(provide :CentralNode/ScrewList "2f6d262f128183ca8a94edda08422d99")


