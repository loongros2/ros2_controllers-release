// Copyright (c) 2021, Stogl Robotics Consulting UG (haftungsbeschränkt)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ROS2_CONTROL_TEST_ASSETS__6D_ROBOT_DESCRIPTION_HPP_
#define ROS2_CONTROL_TEST_ASSETS__6D_ROBOT_DESCRIPTION_HPP_

#include <string>

namespace ros2_control_test_assets
{
const auto valid_6d_robot_urdf =
  R"(
<?xml version="1.0" ?>
<!-- =================================================================================== -->
<!-- |    This document was autogenerated by xacro from ./kr6.urdf.xacro               | -->
<!-- |    EDITING THIS FILE BY HAND IS NOT RECOMMENDED                                 | -->
<!-- =================================================================================== -->
<robot name="kuka_kr6">
  <!-- colours based on RAL values given in "FAQ - Colours of robot and robot
       controller", version "KUKA.Tifs | 2010-01-21 |YM| DefaultColorsRobotAndController.doc",
       downloaded 2015-07-18 from
       http://www.kuka.be/main/cservice/faqs/hardware/DefaultColorsRobotAndController.pdf

       all RAL colours converted using http://www.visual-graphics.de/en/customer-care/ral-colours
  -->
  <link name="base_link">
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <mesh filename="package://ros2_control_test_assets/meshes/visual/base_link.dae"/>
      </geometry>
      <material name="">
        <color rgba="0.5058823529411764 0.47058823529411764 0.38823529411764707 1.0"/>
      </material>
    </visual>
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <mesh filename="package://ros2_control_test_assets/meshes/collision/base_link.stl"/>
      </geometry>
    </collision>
  </link>
  <link name="link_1">
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <mesh filename="package://ros2_control_test_assets/meshes/visual/link_1.dae"/>
      </geometry>
      <material name="">
        <color rgba="0.9647058823529412 0.47058823529411764 0.1568627450980392 1.0"/>
      </material>
    </visual>
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <mesh filename="package://ros2_control_test_assets/meshes/collision/link_1.stl"/>
      </geometry>
    </collision>
  </link>
  <link name="link_2">
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <mesh filename="package://ros2_control_test_assets/meshes/visual/link_2.dae"/>
      </geometry>
      <material name="">
        <color rgba="0.9647058823529412 0.47058823529411764 0.1568627450980392 1.0"/>
      </material>
    </visual>
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <mesh filename="package://ros2_control_test_assets/meshes/collision/link_2.stl"/>
      </geometry>
    </collision>
  </link>
  <link name="link_3">
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <mesh filename="package://ros2_control_test_assets/meshes/visual/link_3.dae"/>
      </geometry>
      <material name="">
        <color rgba="0.9647058823529412 0.47058823529411764 0.1568627450980392 1.0"/>
      </material>
    </visual>
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <mesh filename="package://ros2_control_test_assets/meshes/collision/link_3.stl"/>
      </geometry>
    </collision>
  </link>
  <link name="link_4">
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <mesh filename="package://ros2_control_test_assets/meshes/visual/link_4.dae"/>
      </geometry>
      <material name="">
        <color rgba="0.9647058823529412 0.47058823529411764 0.1568627450980392 1.0"/>
      </material>
    </visual>
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <mesh filename="package://ros2_control_test_assets/meshes/collision/link_4.stl"/>
      </geometry>
    </collision>
  </link>
  <link name="link_5">
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <mesh filename="package://ros2_control_test_assets/meshes/visual/link_5.dae"/>
      </geometry>
      <material name="">
        <color rgba="0.9647058823529412 0.47058823529411764 0.1568627450980392 1.0"/>
      </material>
    </visual>
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <mesh filename="package://ros2_control_test_assets/meshes/collision/link_5.stl"/>
      </geometry>
    </collision>
  </link>
  <link name="link_6">
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <mesh filename="package://ros2_control_test_assets/meshes/visual/link_6.dae"/>
      </geometry>
      <material name="">
        <color rgba="0.5058823529411764 0.47058823529411764 0.38823529411764707 1.0"/>
      </material>
    </visual>
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <mesh filename="package://ros2_control_test_assets/meshes/collision/link_6.stl"/>
      </geometry>
    </collision>
  </link>
  <!-- This frame corresponds to the $FLANGE coordinate system in KUKA KRC controllers. -->
  <link name="tool0"/>
  <joint name="joint_a1" type="revolute">
    <origin rpy="0 0 0" xyz="0 0 0.400"/>
    <parent link="base_link"/>
    <child link="link_1"/>
    <axis xyz="0 0 -1"/>
    <limit effort="0" lower="-2.9670597283903604" upper="2.9670597283903604" velocity="6.283185307179586"/>
  </joint>
  <joint name="joint_a2" type="revolute">
    <origin rpy="0 0 0" xyz="0.025 0 0"/>
    <parent link="link_1"/>
    <child link="link_2"/>
    <axis xyz="0 1 0"/>
    <limit effort="0" lower="-3.3161255787892263" upper="0.7853981633974483" velocity="5.235987755982989"/>
  </joint>
  <joint name="joint_a3" type="revolute">
    <origin rpy="0 0 0" xyz="0.455 0 0"/>
    <parent link="link_2"/>
    <child link="link_3"/>
    <axis xyz="0 1 0"/>
    <limit effort="0" lower="-2.0943951023931953" upper="2.722713633111154" velocity="6.283185307179586"/>
  </joint>
  <joint name="joint_a4" type="revolute">
    <origin rpy="0 0 0" xyz="0 0 0.035"/>
    <parent link="link_3"/>
    <child link="link_4"/>
    <axis xyz="-1 0 0"/>
    <limit effort="0" lower="-3.2288591161895095" upper="3.2288591161895095" velocity="6.649704450098396"/>
  </joint>
  <joint name="joint_a5" type="revolute">
    <origin rpy="0 0 0" xyz="0.420 0 0"/>
    <parent link="link_4"/>
    <child link="link_5"/>
    <axis xyz="0 1 0"/>
    <limit effort="0" lower="-2.0943951023931953" upper="2.0943951023931953" velocity="6.771877497737998"/>
  </joint>
  <joint name="joint_a6" type="revolute">
    <origin rpy="0 0 0" xyz="0.080 0 0"/>
    <parent link="link_5"/>
    <child link="link_6"/>
    <axis xyz="-1 0 0"/>
    <limit effort="0" lower="-6.1086523819801535" upper="6.1086523819801535" velocity="10.733774899765127"/>
  </joint>
  <joint name="joint_a6-tool0" type="fixed">
    <parent link="link_6"/>
    <child link="tool0"/>
    <origin rpy="0 1.5707963267948966 0" xyz="0 0 0"/>
  </joint>
  <!-- ROS base_link to KUKA $ROBROOT coordinate system transform -->
  <link name="base"/>
  <joint name="base_link-base" type="fixed">
    <origin rpy="0 0 0" xyz="0 0 0"/>
    <parent link="base_link"/>
    <child link="base"/>
  </joint>
  <ros2_control name="KukaSystemPositionOnlyHardware" type="system">
    <hardware>
      <plugin>ros2_control_kuka_demo_driver/KukaSystemPositionOnlyHardware</plugin>
      <param name="example_param_hw_start_duration_sec">2.0</param>
      <param name="example_param_hw_stop_duration_sec">3.0</param>
      <param name="example_param_hw_slowdown">2.0</param>
    </hardware>
    <joint name="joint_a1">
      <command_interface name="position">
        <param name="min">-1</param>
        <param name="max">1</param>
      </command_interface>
      <state_interface name="position"/>
    </joint>
    <joint name="joint_a2">
      <command_interface name="position">
        <param name="min">-1</param>
        <param name="max">1</param>
      </command_interface>
      <state_interface name="position"/>
    </joint>
    <joint name="joint_a3">
      <command_interface name="position">
        <param name="min">-1</param>
        <param name="max">1</param>
      </command_interface>
      <state_interface name="position"/>
    </joint>
    <joint name="joint_a4">
      <command_interface name="position">
        <param name="min">-1</param>
        <param name="max">1</param>
      </command_interface>
      <state_interface name="position"/>
    </joint>
    <joint name="joint_a5">
      <command_interface name="position">
        <param name="min">-1</param>
        <param name="max">1</param>
      </command_interface>
      <state_interface name="position"/>
    </joint>
    <joint name="joint_a6">
      <command_interface name="position">
        <param name="min">-1</param>
        <param name="max">1</param>
      </command_interface>
      <state_interface name="position"/>
    </joint>
  </ros2_control>
</robot>
)";

const auto valid_6d_robot_srdf =
  R"(
<?xml version="1.0" ?>
<robot name="kuka_kr6">
    <!--GROUPS: Representation of a set of joints and links. This can be useful for specifying DOF to plan for, defining arms, end effectors, etc-->
    <!--LINKS: When a link is specified, the parent joint of that link (if it exists) is automatically included-->
    <!--JOINTS: When a joint is specified, the child link of that joint (which will always exist) is automatically included-->
    <!--CHAINS: When a chain is specified, all the links along the chain (including endpoints) are included in the group. Additionally, all the joints that are parents to included links are also included. This means that joints along the chain and the parent joint of the base link are included in the group-->
    <!--SUBGROUPS: Groups can also be formed by referencing to already defined group names-->
    <group name="arm">
        <chain base_link="base_link" tip_link="tool0" />
    </group>
    <!--GROUP STATES: Purpose: Define a named state for a particular group, in terms of joint values. This is useful to define states like 'folded arms'-->
    <group_state name="home" group="arm">
        <joint name="joint_a1" value="0" />
        <joint name="joint_a2" value="-1.5708" />
        <joint name="joint_a3" value="1.5708" />
        <joint name="joint_a4" value="0" />
        <joint name="joint_a5" value="1.5708" />
        <joint name="joint_a6" value="0" />
    </group_state>
    <group_state name="zero" group="arm">
        <joint name="joint_a1" value="0" />
        <joint name="joint_a2" value="0" />
        <joint name="joint_a3" value="0" />
        <joint name="joint_a4" value="0" />
        <joint name="joint_a5" value="0" />
        <joint name="joint_a6" value="0" />
    </group_state>
    <!--DISABLE COLLISIONS: By default it is assumed that any link of the robot could potentially come into collision with any other link in the robot. This tag disables collision checking between a specified pair of links. -->
    <disable_collisions link1="base_link" link2="link_1" reason="Adjacent" />
    <disable_collisions link1="link_1" link2="link_2" reason="Adjacent" />
    <disable_collisions link1="link_2" link2="link_3" reason="Adjacent" />
    <disable_collisions link1="link_2" link2="link_4" reason="Never" />
    <disable_collisions link1="link_2" link2="link_5" reason="Never" />
    <disable_collisions link1="link_2" link2="link_6" reason="Never" />
    <disable_collisions link1="link_3" link2="link_4" reason="Adjacent" />
    <disable_collisions link1="link_3" link2="link_5" reason="Never" />
    <disable_collisions link1="link_3" link2="link_6" reason="Never" />
    <disable_collisions link1="link_4" link2="link_5" reason="Adjacent" />
    <disable_collisions link1="link_4" link2="link_6" reason="Never" />
    <disable_collisions link1="link_5" link2="link_6" reason="Adjacent" />
</robot>

)";

}  // namespace ros2_control_test_assets

#endif  // ROS2_CONTROL_TEST_ASSETS__6D_ROBOT_DESCRIPTION_HPP_
