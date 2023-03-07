%bcond_without tests
%bcond_without weak_deps

%global __os_install_post %(echo '%{__os_install_post}' | sed -e 's!/usr/lib[^[:space:]]*/brp-python-bytecompile[[:space:]].*$!!g')
%global __provides_exclude_from ^/opt/ros/rolling/.*$
%global __requires_exclude_from ^/opt/ros/rolling/.*$

Name:           ros-rolling-admittance-controller
Version:        3.3.0
Release:        1%{?dist}%{?release_suffix}
Summary:        ROS admittance_controller package

License:        Apache License 2.0
Source0:        %{name}-%{version}.tar.gz

Requires:       ros-rolling-backward-ros
Requires:       ros-rolling-control-msgs
Requires:       ros-rolling-control-toolbox
Requires:       ros-rolling-controller-interface
Requires:       ros-rolling-filters
Requires:       ros-rolling-generate-parameter-library
Requires:       ros-rolling-geometry-msgs
Requires:       ros-rolling-hardware-interface
Requires:       ros-rolling-joint-trajectory-controller
Requires:       ros-rolling-kinematics-interface
Requires:       ros-rolling-pluginlib
Requires:       ros-rolling-rclcpp
Requires:       ros-rolling-rclcpp-lifecycle
Requires:       ros-rolling-realtime-tools
Requires:       ros-rolling-tf2
Requires:       ros-rolling-tf2-eigen
Requires:       ros-rolling-tf2-geometry-msgs
Requires:       ros-rolling-tf2-kdl
Requires:       ros-rolling-tf2-ros
Requires:       ros-rolling-trajectory-msgs
Requires:       ros-rolling-ros-workspace
BuildRequires:  ros-rolling-ament-cmake
BuildRequires:  ros-rolling-backward-ros
BuildRequires:  ros-rolling-control-msgs
BuildRequires:  ros-rolling-control-toolbox
BuildRequires:  ros-rolling-controller-interface
BuildRequires:  ros-rolling-filters
BuildRequires:  ros-rolling-generate-parameter-library
BuildRequires:  ros-rolling-geometry-msgs
BuildRequires:  ros-rolling-hardware-interface
BuildRequires:  ros-rolling-joint-trajectory-controller
BuildRequires:  ros-rolling-kinematics-interface
BuildRequires:  ros-rolling-pluginlib
BuildRequires:  ros-rolling-rclcpp
BuildRequires:  ros-rolling-rclcpp-lifecycle
BuildRequires:  ros-rolling-realtime-tools
BuildRequires:  ros-rolling-tf2
BuildRequires:  ros-rolling-tf2-eigen
BuildRequires:  ros-rolling-tf2-geometry-msgs
BuildRequires:  ros-rolling-tf2-kdl
BuildRequires:  ros-rolling-tf2-ros
BuildRequires:  ros-rolling-trajectory-msgs
BuildRequires:  ros-rolling-ros-workspace
Provides:       %{name}-devel = %{version}-%{release}
Provides:       %{name}-doc = %{version}-%{release}
Provides:       %{name}-runtime = %{version}-%{release}

%if 0%{?with_tests}
BuildRequires:  ros-rolling-ament-cmake-gmock
BuildRequires:  ros-rolling-controller-manager
BuildRequires:  ros-rolling-kinematics-interface-kdl
BuildRequires:  ros-rolling-ros2-control-test-assets
%endif

%description
Implementation of admittance controllers for different input and output
interface.

%prep
%autosetup -p1

%build
# In case we're installing to a non-standard location, look for a setup.sh
# in the install tree and source it.  It will set things like
# CMAKE_PREFIX_PATH, PKG_CONFIG_PATH, and PYTHONPATH.
if [ -f "/opt/ros/rolling/setup.sh" ]; then . "/opt/ros/rolling/setup.sh"; fi
mkdir -p .obj-%{_target_platform} && cd .obj-%{_target_platform}
%cmake3 \
    -UINCLUDE_INSTALL_DIR \
    -ULIB_INSTALL_DIR \
    -USYSCONF_INSTALL_DIR \
    -USHARE_INSTALL_PREFIX \
    -ULIB_SUFFIX \
    -DCMAKE_INSTALL_PREFIX="/opt/ros/rolling" \
    -DAMENT_PREFIX_PATH="/opt/ros/rolling" \
    -DCMAKE_PREFIX_PATH="/opt/ros/rolling" \
    -DSETUPTOOLS_DEB_LAYOUT=OFF \
%if !0%{?with_tests}
    -DBUILD_TESTING=OFF \
%endif
    ..

%make_build

%install
# In case we're installing to a non-standard location, look for a setup.sh
# in the install tree and source it.  It will set things like
# CMAKE_PREFIX_PATH, PKG_CONFIG_PATH, and PYTHONPATH.
if [ -f "/opt/ros/rolling/setup.sh" ]; then . "/opt/ros/rolling/setup.sh"; fi
%make_install -C .obj-%{_target_platform}

%if 0%{?with_tests}
%check
# Look for a Makefile target with a name indicating that it runs tests
TEST_TARGET=$(%__make -qp -C .obj-%{_target_platform} | sed "s/^\(test\|check\):.*/\\1/;t f;d;:f;q0")
if [ -n "$TEST_TARGET" ]; then
# In case we're installing to a non-standard location, look for a setup.sh
# in the install tree and source it.  It will set things like
# CMAKE_PREFIX_PATH, PKG_CONFIG_PATH, and PYTHONPATH.
if [ -f "/opt/ros/rolling/setup.sh" ]; then . "/opt/ros/rolling/setup.sh"; fi
CTEST_OUTPUT_ON_FAILURE=1 \
    %make_build -C .obj-%{_target_platform} $TEST_TARGET || echo "RPM TESTS FAILED"
else echo "RPM TESTS SKIPPED"; fi
%endif

%files
/opt/ros/rolling

%changelog
* Tue Mar 07 2023 Denis Štogl <denis@stogl.de> - 3.3.0-1
- Autogenerated by Bloom

* Fri Feb 10 2023 Denis Štogl <denis@stogl.de> - 3.2.0-1
- Autogenerated by Bloom

* Thu Jan 26 2023 Denis Štogl <denis@stogl.de> - 3.1.0-1
- Autogenerated by Bloom

* Thu Jan 19 2023 Denis Štogl <denis@stogl.de> - 3.0.0-1
- Autogenerated by Bloom

* Thu Jan 12 2023 Denis Štogl <denis@stogl.de> - 2.16.0-1
- Autogenerated by Bloom

* Tue Dec 06 2022 Denis Štogl <denis@stogl.de> - 2.15.0-1
- Autogenerated by Bloom

* Fri Nov 18 2022 Denis Štogl <denis@stogl.de> - 2.14.0-1
- Autogenerated by Bloom

