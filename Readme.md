<h1>Notes</h1>
<ul>
  <li>Many functions accept pointers as arguments as well as values. If a function does this, only the version that acceps values will be documented in the <b>Function Syntax</b> section.
</ul>

<hr />

<h1>Classes and Structures</h1>

<ul>
  
  <li><h3>vector2</h3>
    <ul>
      <li>stores x (float) as the x value of the vector</li>
      <li>stores y (float) as the y value of the vector</li>
    </ul>
    <br />
    <ul>
      <li>vector2(float x, float y): creates a new vector2 with position (x, y)</li>
      <li>vector2(float xy): creates a new vector2 with position (xy, xy)</li>
      <li>vector2(): creates a new vector2 with position (0, 0)</li>
    </ul>
    <br />
    <ul>
      <li>operators that can be used consist of +, -, *, /, +=, -=, *=, /=, ==, =</li>
    </ul>
  </li>
  
  <li><h3>camera</h3>
    <ul>
      <li>stores position (vector2) as the position of the camera</li>
    </ul>
    <br />
    <ul>
      <li>camera(vector2 position, vector2 windowsize, int mode = CAMERAMODE_CENTERED): takes in the position of the camera, the size of the game window, and the mode of the camera, creates a new camera with these properties</li>
      <li>applyCamera(vector2 position) takes an absolute position, converts it to a position relative to the top left corner of the screen, and returns that</li>
      <li>setMode(int mode): takes in a mode and sets the camera's mode</li>
      <li>setWindowSize(vector2 windowSize): takes in a the size of the game window and sets the camera's window size to this</li>
    </ul>
    <br />
    <ul>
      <li>setWindowSize() can be inefficient due to having to re-calculate the mode of the camera in order to change the window size.</li>
      <li>The mode is where the picture is relative to the camera's position. For example, if the camera is set to CAMERAMODE_TOPLEFT, the view of the camera will be a rectangle with min(cameraPosition) and max(cameraPosition + windowSize). Likewise, if the camera is set to CAMERAMODE_BOTTOMRIGHT, the view of the camera will be a rectangle with min(cameraPosition - windowSize) and max(cameraPosition)</li>
    </ul>
  </li>
  
  <li> <h3>animation<T></h3>
    <ul>
      <li>stores frames (std::vector<T>) as the frames of the animation</li>
      <li>stores speed (float) as the speed of the animation (frames per second)</li>
    </ul>
    <br />
    <ul>
      <li>update(float dt): uses the deltaTime (time since the last frame) to update the animation</li>
      <li>getCurrentFrame(): returns a pointer to the current frame of the animation</li>
    </ul>
  </li>
</ul>

<hr />
  
<h1>Function syntax: </h1>

<h2>Core functions:</h2>

<ul>
  <li>distance(vector2 a, vector2 b): calculates the distance between points a and b, returns that distance</li>
  <li>distanceSquared(vector2 a, vector2 b): calculates the distance squared between a and b, and returns that distance (much faster than just calculating distance)</li>
</ul>

<ul>
</ul>
