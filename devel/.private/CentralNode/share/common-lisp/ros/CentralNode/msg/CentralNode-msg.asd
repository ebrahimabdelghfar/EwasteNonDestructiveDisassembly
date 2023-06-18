
(cl:in-package :asdf)

(defsystem "CentralNode-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "node_response" :depends-on ("_package_node_response"))
    (:file "_package_node_response" :depends-on ("_package"))
  ))