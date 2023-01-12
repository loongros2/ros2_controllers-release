%bcond_without tests
%bcond_without weak_deps

%global __os_install_post %(echo '%{__os_install_post}' | sed -e 's!/usr/lib[^[:space:]]*/brp-python-bytecompile[[:space:]].*$!!g')
%global __provides_exclude_from ^/opt/ros/rolling/.*$
%global __requires_exclude_from ^/opt/ros/rolling/.*$

Name:           ros-rolling-rqt-joint-trajectory-controller
Version:        2.16.0
Release:        1%{?dist}%{?release_suffix}
Summary:        ROS rqt_joint_trajectory_controller package

License:        Apache-2.0
Source0:        %{name}-%{version}.tar.gz

Requires:       python%{python3_pkgversion}-rospkg
Requires:       ros-rolling-control-msgs
Requires:       ros-rolling-controller-manager-msgs
Requires:       ros-rolling-python-qt-binding
Requires:       ros-rolling-qt-gui
Requires:       ros-rolling-rclpy
Requires:       ros-rolling-rqt-gui
Requires:       ros-rolling-rqt-gui-py
Requires:       ros-rolling-trajectory-msgs
Requires:       ros-rolling-ros-workspace
BuildRequires:  python%{python3_pkgversion}-devel
BuildRequires:  ros-rolling-ros-workspace
Provides:       %{name}-devel = %{version}-%{release}
Provides:       %{name}-doc = %{version}-%{release}
Provides:       %{name}-runtime = %{version}-%{release}

%description
Graphical frontend for interacting with joint_trajectory_controller instances.

%prep
%autosetup -p1

%build
# In case we're installing to a non-standard location, look for a setup.sh
# in the install tree and source it.  It will set things like
# CMAKE_PREFIX_PATH, PKG_CONFIG_PATH, and PYTHONPATH.
if [ -f "/opt/ros/rolling/setup.sh" ]; then . "/opt/ros/rolling/setup.sh"; fi
%py3_build

%install
# In case we're installing to a non-standard location, look for a setup.sh
# in the install tree and source it.  It will set things like
# CMAKE_PREFIX_PATH, PKG_CONFIG_PATH, and PYTHONPATH.
if [ -f "/opt/ros/rolling/setup.sh" ]; then . "/opt/ros/rolling/setup.sh"; fi
%py3_install -- --prefix "/opt/ros/rolling"

%if 0%{?with_tests}
%check
# Look for a directory with a name indicating that it contains tests
TEST_TARGET=$(ls -d * | grep -m1 "\(test\|tests\)" ||:)
if [ -n "$TEST_TARGET" ] && %__python3 -m pytest --version; then
# In case we're installing to a non-standard location, look for a setup.sh
# in the install tree and source it.  It will set things like
# CMAKE_PREFIX_PATH, PKG_CONFIG_PATH, and PYTHONPATH.
if [ -f "/opt/ros/rolling/setup.sh" ]; then . "/opt/ros/rolling/setup.sh"; fi
%__python3 -m pytest $TEST_TARGET || echo "RPM TESTS FAILED"
else echo "RPM TESTS SKIPPED"; fi
%endif

%files
/opt/ros/rolling

%changelog
* Thu Jan 12 2023 Bence Magyar <bence.magyar.robotics@gmail.com> - 2.16.0-1
- Autogenerated by Bloom

* Tue Dec 06 2022 Bence Magyar <bence.magyar.robotics@gmail.com> - 2.15.0-1
- Autogenerated by Bloom

* Fri Nov 18 2022 Bence Magyar <bence.magyar.robotics@gmail.com> - 2.14.0-1
- Autogenerated by Bloom

* Wed Oct 05 2022 Bence Magyar <bence.magyar.robotics@gmail.com> - 2.13.0-1
- Autogenerated by Bloom

* Thu Sep 01 2022 Bence Magyar <bence.magyar.robotics@gmail.com> - 2.12.0-1
- Autogenerated by Bloom

* Thu Aug 04 2022 Bence Magyar <bence.magyar.robotics@gmail.com> - 2.11.0-1
- Autogenerated by Bloom

* Mon Aug 01 2022 Bence Magyar <bence.magyar.robotics@gmail.com> - 2.10.0-1
- Autogenerated by Bloom

