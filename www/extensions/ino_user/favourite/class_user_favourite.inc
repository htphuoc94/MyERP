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
 * 
 *
 */
class user_favourite extends dbObject {

 public static $table_name = "user_favourite";
 public static $primary_column = "user_favourite_id";
 public static $key_column = 'fav_name';
 public static $module = "extensions";
 public static $system_info = [
  'name' => 'User Favourite',
  'number' => '10029',
  'description' => 'Define and mainten favourite',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 29
 ];
 public $field_a = [
  'user_favourite_id',
  'fav_name',
  'fav_group',
  'user_id',
  'path_id',
  'external_link',
  'priority',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'user_id',
  'path_id',
 ];
 public $requiredField = [
  'user_id',
  'fav_name',
 ];
 public $user_favourite_id;
 public $user_id;
 public $fav_name;
 public $fav_group;
 public $path_id;
 public $external_link;
 public $priority;
 public $comment_by;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 Public static function favourite_group() {
  $option_type = option_header::find_by_name('USER_FAVOURITE_GROUP');
  $option_line = option_line::find_by_option_id($option_type->option_header_id);
  return $option_line;
 }

 public function findBy_userId() {
  $sql = "SELECT * FROM " . self::$table_name . " where user_id='{$this->user_id}' ";
  $result = $this->findBySql($sql);
  return !empty($result) ? $result : false;
 }

 public function findBy_currentUser() {
  if ($_SESSION['user_id']) {
   $this->user_id = $_SESSION['user_id'];
   return $this->findBy_userId();
  } else {
   return false;
  }
 }

 public function show_currentUser_fav($show_as_menu = false, $ul_details='' , $li_class= '' ) {
  $favs = $this->findBy_currentUser();
  if (!$favs) {
   return false;
  }
  $ul_divClass = ($show_as_menu == true ) ? ' class="dropdown-menu" role="menu" ' : $ul_details;
  $fav_stmt = '<ul id="favourite" '.$ul_divClass.' >';
  $count = 0;
  foreach ($favs as $links) {
   $divClass = ($count % 2 ) == 0 ? ' even ' : ' odd ';
   $divClass .= $li_class;
   $fav_stmt .= '<li class="' . $divClass . '">';
   if (!empty($links->path_id)) {
    $path = path::find_by_id($links->path_id);
    $url_1 = htmlspecialchars(HOME_URL . $path->path_link);
    $fav_stmt .= '<a class="getAjaxForm" href="' . $url_1 . '">' . $links->fav_name . '</a>';
   } else {
    $url_1 = htmlspecialchars($links->external_link);
    $fav_stmt .= '<a target="_new" href="http://' . $url_1 . '">' . $links->fav_name . '</a>';
   }
   $fav_stmt .= '</li>';
  }
  $fav_stmt .= '</ul>';
  return $fav_stmt;
 }

 public static function find_by_userId($user_id) {
  $sql = "SELECT * FROM " . self::$table_name . " where user_id='{$user_id}' ";
  $result = $this->findBySql($sql);
  return !empty($result) ? $result : false;
 }

 public static function user_favourite_all_v() {
  global $db;
  $sql = " SELECT * FROM ";
  $sql .=" user_favourite AS rp , option_line  AS ol";
  $sql .=" WHERE rp.role_code = ol.option_line_id ";

  $result = $db->result_array_assoc($sql);

  return $result;
 }

 Public static function all_roles() {
  $option_header = option_header::find_by_name('USER_ROLES');
  $all_roles = option_line::find_by_option_id($option_header->option_header_id);
  return $all_roles;
 }

}

$user_favourite = new user_favourite();
$fav = &$user_favourite;
?>
