<h1>Notes</h1>
<ul>
  <li>Many functions accept pointers as arguments as well as values. If a function does this, only the version that acceps values will be documented in the <b>Function Syntax</b> section.
</ul>

<hr />

<h1>Classes and Structures</h1>

<ul>
  
  <li><h3>vector2</h3>
    <ul>
      <li>vector2(x, y): self explanitory</li>
      <li>vector2(xy): sets x and y to xy</li>
      <li>vector2(): sets x and y to 0</li>
    </ul>
  </li>
  
  <li><h3>camera</h3>
    <ul>
      <li>camera(vector2 position, vector2 windowsize, int mode = CAMERAMODE_CENTERED): position is position of the camera, windowsize is the size of the current window, mode is self explanitory</li>
    </ul>
  </li>
</ul>

<hr />
  
<h1>Function syntax: </h1>

<h2>Core functions:</h2>

<ul>
  <li>distance(vector2 a, vector2 b): calculates the distance between points a and b</li>
  <li>distanceSquared(vector2 a, vector2 b): calculates the distance squared between a and b (much faster than just calculating distance)</li>
</ul>

<ul>
  <li>camera::applyCamera(vector2 objectPosition): calculates the position relative to the top left of the screen that the object position should be drawn (object position is the <i>absolute</i> position of an object)</li>
  <li>camera::setMode(int mode): sets the mode of the camera to mode.</li>
  <li>camera::setWindowSize(vector2 windowSize): sets the window size stored in the camera. (note that this can be inefficient due to having to calculate what mode the camera is in)</li>
</ul>
