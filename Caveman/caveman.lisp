(defpackage :caveman
  (:use :cl))

(in-package :caveman)

(defvar *bob* '(nil 0))
(defvar *bub* '(nil 0))

;; Utility Functions
(defun split-string (string delim)
  "Returns a list of substring from input string that were split by delim."
  (loop i = 0 for (1+ j)
       as j = (position delim string :start i)
       collect (subseq string i j)
       while j))

(defun get-args ()
  "Get args returns a split list of input arguments."
  (split-string (second *posix-argv*) #\,))

(defun get-chars (string)
  "Returns a list of characters from string."
  )

