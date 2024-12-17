import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/ros2/CHAPT4/CHAPT4_WS/install/demo_python_service'
