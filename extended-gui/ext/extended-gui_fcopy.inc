<?php
/*
    extended-gui_fcopy.inc

    Copyright (c) 2014, Andreas Schmidhuber
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
    ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

    The views and conclusions contained in the software and documentation are those
    of the authors and should not be interpreted as representing official policies,
    either expressed or implied, of the FreeBSD Project.
*/
// files which will be used/replaced by extended-gui (file name, original location)
$files = array(
//-------------------------------> /usr/local/www/
  // for Status | System page extensions
    array("index.php","/usr/local/www/"),
    array("graph_index.php","/usr/local/www/"),
    array("graph_index_cpu.php","/usr/local/www/"),
  // for Diagnostics | Log page search and user column amendment 
    array("diag_log.inc","/usr/local/www/"),
    array("diag_log.php","/usr/local/www/"),
  // for Status | Disks page amendment additional column Activity
    array("status_disks.php","/usr/local/www/"),
  // for Access | Users page amendment showing all groups a user belongs to
    array("access_users.php","/usr/local/www/"),
  // for Status | Graph time changes
    array("graph.php","/usr/local/www/"),
    array("status_graph.php","/usr/local/www/"),
    array("graph_cpu.php","/usr/local/www/"),
    array("status_graph_cpu.php","/usr/local/www/"),
  // for Disks | ZFS | Datasets & Volumes error traps and ...
    array("disks_zfs_dataset.php","/usr/local/www/"),
    array("disks_zfs_volume.php","/usr/local/www/"),
  // ... extended apply message
    array("guiconfig.inc","/usr/local/www/"),
//-------------------------------> /etc/inc/
  // for Status | System page extensions
    array("system.inc","/etc/inc/"),
);

$backup_path = $config['extended-gui']['rootfolder']."backup/";
$extend_path = $config['extended-gui']['rootfolder']."files/";

function copy_origin2backup ($files, $backup_path, $extend_path) {
    foreach ($files as $file) {
        if (is_file($file[1].$file[0])) {
            if (! copy($file[1].$file[0], $backup_path.$file[0])) {
                $msg="failed to copy $file[0] from $file[1] to $backup_path"; 
                exec ('logger extended-gui: '.$msg); $error_msg[]=$msg;
            }
        }
    }
    return $error_msg;
}                                                                              

function copy_backup2origin ($files, $backup_path, $extend_path) {
    foreach ($files as $file) {
        if (is_file($backup_path.$file[0])) {
            if (! copy($backup_path.$file[0], $file[1].$file[0])) {
                $msg="failed to copy $file[0] from $backup_path to $file[1]";
                exec ('logger extended-gui: '.$msg); $error_msg[]=$msg;
            }
        }
    }
    return $error_msg;
}

function copy_extended2origin ($files, $backup_path, $extend_path) {
    foreach ($files as $file) {
        if (! copy($extend_path.$file[0], $file[1].$file[0])) {
            $msg="failed to copy $file[0] from $extend_path to $file[1]"; 
            exec ('logger extended-gui: '.$msg); $error_msg[]=$msg;
        }
    }
    return $error_msg;
}
?>
