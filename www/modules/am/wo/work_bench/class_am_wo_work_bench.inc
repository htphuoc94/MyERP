<?php
/**
 * MyERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/MyERP/MyERP
 */
/**
 * am_wo_work_bench 
 *
 */
class am_wo_work_bench extends am_move_transaction {
    public static $system_info = [
  'name' => 'WO Work Bench',
  'number' => '4115',
  'description' => 'Work Order Work Bench',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'wip',
  'weight' => 8
 ];
 public $pageTitle = " WO Work Bench"; //page Title
 
// public function _before_save() {
//  $wwbl = new am_wo_work_bench_line();
//  $wwbl->_before_save();
// }

}

//end of resource class
?>