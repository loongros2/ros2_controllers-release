%bcond_without tests
%bcond_without weak_deps

%global __os_install_post %(echo '%{__os_install_post}' | sed -e 's!/usr/lib[^[:space:]]*/brp-python-bytecompile[[:space:]].*$!!g')
%global __provides_exclude_from ^/opt/ros/iron/.*$
%global __requires_exclude_from ^/opt/ros/iron/.*$

Name:           ros-iron-pid-controller
Version:        3.27.0
Release:        1%{?dist}%{?release_suffix}
Summary:        ROS pid_controller package

License:        Apache-2.0
Source0:        %{name}-%{version}.tar.gz

Requires:       ros-iron-angles
Requires:       ros-iron-backward-ros
Requires:       ros-iron-control-msgs
Requires:       ros-iron-control-toolbox
Requires:       ros-iron-controller-interface
Requires:       ros-iron-hardware-interface
Requires:       ros-iron-parameter-traits
Requires:       ros-iron-pluginlib
Requires:       ros-iron-rclcpp
Requires:       ros-iron-rclcpp-lifecycle
Requires:       ros-iron-realtime-tools
Requires:       ros-iron-std-srvs
Requires:       ros-iron-ros-workspace
BuildRequires:  ros-iron-ament-cmake
BuildRequires:  ros-iron-angles
BuildRequires:  ros-iron-backward-ros
BuildRequires:  ros-iron-control-msgs
BuildRequires:  ros-iron-control-toolbox
BuildRequires:  ros-iron-controller-interface
BuildRequires:  ros-iron-generate-parameter-library
BuildRequires:  ros-iron-hardware-interface
BuildRequires:  ros-iron-parameter-traits
BuildRequires:  ros-iron-pluginlib
BuildRequires:  ros-iron-rclcpp
BuildRequires:  ros-iron-rclcpp-lifecycle
BuildRequires:  ros-iron-realtime-tools
BuildRequires:  ros-iron-std-srvs
BuildRequires:  ros-iron-ros-workspace
Provides:       %{name}-devel = %{version}-%{release}
Provides:       %{name}-doc = %{version}-%{release}
Provides:       %{name}-runtime = %{version}-%{release}

%if 0%{?with_tests}
BuildRequires:  ros-iron-ament-cmake-gmock
BuildRequires:  ros-iron-controller-manager
BuildRequires:  ros-iron-hardware-interface-testing
BuildRequires:  ros-iron-ros2-control-test-assets
%endif

%description
Controller based on PID implememenation from control_toolbox package.

%prep
%autosetup -p1

%build
# In case we're installing to a non-standard location, look for a setup.sh
# in the install tree and source it.  It will set things like
# CMAKE_PREFIX_PATH, PKG_CONFIG_PATH, and PYTHONPATH.
if [ -f "/opt/ros/iron/setup.sh" ]; then . "/opt/ros/iron/setup.sh"; fi
mkdir -p .obj-%{_target_platform} && cd .obj-%{_target_platform}
%cmake3 \
    -UINCLUDE_INSTALL_DIR \
    -ULIB_INSTALL_DIR \
    -USYSCONF_INSTALL_DIR \
    -USHARE_INSTALL_PREFIX \
    -ULIB_SUFFIX \
    -DCMAKE_INSTALL_PREFIX="/opt/ros/iron" \
    -DAMENT_PREFIX_PATH="/opt/ros/iron" \
    -DCMAKE_PREFIX_PATH="/opt/ros/iron" \
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
if [ -f "/opt/ros/iron/setup.sh" ]; then . "/opt/ros/iron/setup.sh"; fi
%make_install -C .obj-%{_target_platform}

%if 0%{?with_tests}
%check
# Look for a Makefile target with a name indicating that it runs tests
TEST_TARGET=$(%__make -qp -C .obj-%{_target_platform} | sed "s/^\(test\|check\):.*/\\1/;t f;d;:f;q0")
if [ -n "$TEST_TARGET" ]; then
# In case we're installing to a non-standard location, look for a setup.sh
# in the install tree and source it.  It will set things like
# CMAKE_PREFIX_PATH, PKG_CONFIG_PATH, and PYTHONPATH.
if [ -f "/opt/ros/iron/setup.sh" ]; then . "/opt/ros/iron/setup.sh"; fi
CTEST_OUTPUT_ON_FAILURE=1 \
    %make_build -C .obj-%{_target_platform} $TEST_TARGET || echo "RPM TESTS FAILED"
else echo "RPM TESTS SKIPPED"; fi
%endif

%files
/opt/ros/iron

%changelog
* Sat Nov 02 2024 Bence Magyar <bence.magyar.robotics@gmail.com> - 3.27.0-1
- Autogenerated by Bloom

* Wed Sep 11 2024 Bence Magyar <bence.magyar.robotics@gmail.com> - 3.26.3-1
- Autogenerated by Bloom

* Thu Aug 22 2024 Bence Magyar <bence.magyar.robotics@gmail.com> - 3.26.2-1
- Autogenerated by Bloom

* Wed Aug 14 2024 Bence Magyar <bence.magyar.robotics@gmail.com> - 3.26.1-1
- Autogenerated by Bloom

* Wed Jul 24 2024 Bence Magyar <bence.magyar.robotics@gmail.com> - 3.26.0-1
- Autogenerated by Bloom

* Tue Jul 09 2024 Bence Magyar <bence.magyar.robotics@gmail.com> - 3.25.0-1
- Autogenerated by Bloom

