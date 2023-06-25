;; Auto-generated. Do not edit!


(when (boundp 'CentralNode::node_response)
  (if (not (find-package "CENTRALNODE"))
    (make-package "CENTRALNODE"))
  (shadow 'node_response (find-package "CENTRALNODE")))
(unless (find-package "CENTRALNODE::NODE_RESPONSE")
  (make-package "CENTRALNODE::NODE_RESPONSE"))

(in-package "ROS")
;;//! \htmlinclude node_response.msg.html


(defclass CentralNode::node_response
  :super ros::object
  :slots (_nodeId _extraMessage _status ))

(defmethod CentralNode::node_response
  (:init
   (&key
    ((:nodeId __nodeId) 0)
    ((:extraMessage __extraMessage) "")
    ((:status __status) 0)
    )
   (send-super :init)
   (setq _nodeId (round __nodeId))
   (setq _extraMessage (string __extraMessage))
   (setq _status (round __status))
   self)
  (:nodeId
   (&optional __nodeId)
   (if __nodeId (setq _nodeId __nodeId)) _nodeId)
  (:extraMessage
   (&optional __extraMessage)
   (if __extraMessage (setq _extraMessage __extraMessage)) _extraMessage)
  (:status
   (&optional __status)
   (if __status (setq _status __status)) _status)
  (:serialization-length
   ()
   (+
    ;; int32 _nodeId
    4
    ;; string _extraMessage
    4 (length _extraMessage)
    ;; uint8 _status
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _nodeId
       (write-long _nodeId s)
     ;; string _extraMessage
       (write-long (length _extraMessage) s) (princ _extraMessage s)
     ;; uint8 _status
       (write-byte _status s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _nodeId
     (setq _nodeId (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; string _extraMessage
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _extraMessage (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint8 _status
     (setq _status (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get CentralNode::node_response :md5sum-) "b888e972b0112a456a30ae15a1f395cd")
(setf (get CentralNode::node_response :datatype-) "CentralNode/node_response")
(setf (get CentralNode::node_response :definition-)
      "int32 nodeId
string extraMessage
uint8 status
")



(provide :CentralNode/node_response "b888e972b0112a456a30ae15a1f395cd")


