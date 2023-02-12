# Kernel-System-Call

To create the system call, we need to define a SYSCALL_DEFINE function in the sys.c file of
the kernel. To do the 2d-array copy, I have created pointer to an array of maximum size 1024 in
the kernel space and used the __copy_from_user and __copy_to_user to copy from the user
space to the kernel space and back to the user space. If __copy_to_user and
__copy_from__user don't work then -EFAULT is returned and in case of success it returns 0.
Any size of matrix (below 1024) can be copied this way. Next we add the syscall to the
syscall_64.tbl in the syscalls directory. The patch.txt file shows the differences made to the sys.c
file and syscall_64.tbl file.
Now we compile the kernel with the newly added syscall using the make -j2 command and
configure our kernel
Next, to test the file I have hardcoded a source_matrix of 4X3. There is a syscall made to the
system call that was added. On running the file we see that the source array elements have
been copied to the destination matrix
