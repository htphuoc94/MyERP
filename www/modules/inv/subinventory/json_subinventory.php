<?php 

require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../MyERP_server/includes/basics/basics.inc');


if (!empty($_GET['org_id']) && ($_GET['find_all_subinventory'] = 1)) {
 echo '<div id="json_subinventory_find_all">';
 $subinv = new subinventory();
 $subinv->org_id = $_GET['org_id'];
 $subinventory_of_org = $subinv->findAll_ofOrgid();
 if (empty($subinventory_of_org)) {
	return false;
 } else {
	echo '<option value=""></option>';
	foreach ($subinventory_of_org as $key => $value) {
	 echo '<option value="' . $value->subinventory_id . '"';
	 echo '>' . $value->subinventory . '</option>';
	}
 }
 echo '</div>';
}
?>

