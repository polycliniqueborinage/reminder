<?php
?>
<div id='dashboard' style='height:800px'>
	<div class="ui-layout-center">
	<div id='calendar'></div>
	<div id="event_edit_container">
		<form>
			<input type="hidden" />
			<ul>
				<li>
					<span>Date: </span><span class="date_holder"></span> 
				</li>
				<li>
					<label for="start">Start Time: </label><select name="start"><option value="">Select Start Time</option></select>
				</li>
				<li>
					<label for="end">End Time: </label><select name="end"><option value="">Select End Time</option></select>
				</li>
				<li>
					<label for="title">Title: </label><input type="text" name="title" />
				</li>
				<li>
					<label for="location">Location: </label><input type="text" name="location" />
				</li>
				<li>
					<label for="body">Body: </label><textarea name="body"></textarea>
				</li>
			</ul>
		</form>
	</div>
	</div>
	<div class="ui-layout-west">
	
		<div id="datepicker"></div>
		
		<div class="nb_0">
			<h2>
				Mes agendas
			</h2>
			<ul>
				<li>
				1111
				</li>
				<li>
				222
				</li>
			</ul>
		</div>
	
		<?php print $west; ?>
	
	</div>
</div>