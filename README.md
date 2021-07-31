# examples_ros2
ROS2 is a growing backbone for a variety of robotic systems. While the [ROS2 Documentation](https://docs.ros.org/en/galactic/Tutorials.html) is much better than that for ROS, there are significant gaps in knowledge (or a least it can be difficult to find) in forums and the documentation. The intent of these tutorials is to highlight some of the features that are less commonly known or lack readily accessible documentation (beyond the API/source code). Additionally, for the purposes of this code, we assume relatively new users to note only ROS2 but also programming more broadly. As such, there is great emphasis of highlighting edge cases and poking at the implications of the ROS2 structure. We hope this will also contribute to understanding possible paradigms of writing software with ROS2 and how these interact with intended use.

## Available Examples


### Completed

#### Logging

```
logging in class (node objects)

logging in main

logging severity and flags

logging with expressions

logging with functions

logging once

logging skipfirst

logging with stream

logging with throttling
```

### Planned examples

#### Launch

```
Launch examples highlighting different sytanx options
```

#### Multithreading

```
Single Threading with Executors

Multithreading examples (tbd)
```

#### Nodes

```
Picking at wall timer based paradigms and other features
```

#### Parameters

```
getting basic parameters (int/double and similar types, strings, chars, bools, etc)

getting vectors of parameters

getting more complex parameter data and scope
```

#### Spin

```
spin

spin some

spin until future completed
```

## TODO

Check back for logging ROS message datatypes with stream

Try to implement Logging with functions for non-static member variables

Work on ReadTheDocs based documentation to provide commentary on the lessons gleaned from examples

