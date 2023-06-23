
(cl:in-package :asdf)

(defsystem "CentralNode-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Schedular" :depends-on ("_package_Schedular"))
    (:file "_package_Schedular" :depends-on ("_package"))
    (:file "ScrewList" :depends-on ("_package_ScrewList"))
    (:file "_package_ScrewList" :depends-on ("_package"))
  ))