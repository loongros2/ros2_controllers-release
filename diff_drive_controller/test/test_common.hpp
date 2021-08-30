// Copyright 2020 PAL Robotics SL.
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

#ifndef TEST_COMMON_HPP_
#define TEST_COMMON_HPP_

namespace diff_drive_controller_testing
{
constexpr auto diffbot_urdf =
  R"(

<?xml version="1.0" ?>
<!-- =================================================================================== -->
<!-- |    This document was autogenerated by xacro from diffbot.xacro                  | -->
<!-- |    EDITING THIS FILE BY HAND IS NOT RECOMMENDED                                 | -->
<!-- =================================================================================== -->
<robot name="robot">
  <!-- Space btw top of beam and the each joint -->
  <!-- Links: inertial,visual,collision -->
  <link name="base_link">
    <inertial>
      <!-- origin is relative -->
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <mass value="5"/>
      <inertia ixx="5" ixy="0" ixz="0" iyy="5" iyz="0" izz="5"/>
    </inertial>
    <visual>
      <geometry>
        <box size="0.5 0.1 0.1"/>
      </geometry>
    </visual>
    <collision>
      <!-- origin is relative -->
      <origin xyz="0 0 0"/>
      <geometry>
        <box size="0.5 0.1 0.1"/>
      </geometry>
    </collision>
  </link>
  <link name="base_footprint">
    <visual>
      <geometry>
        <sphere radius="0.01"/>
      </geometry>
    </visual>
    <collision>
      <origin xyz="0 0 0"/>
      <geometry>
        <sphere radius="0.00000001"/>
      </geometry>
    </collision>
  </link>
  <joint name="base_footprint_joint" type="fixed">
    <origin rpy="0 0 0" xyz="0 0 0.11"/>
    <child link="base_link"/>
    <parent link="base_footprint"/>
  </joint>
  <link name="wheel_0_link">
    <inertial>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <mass value="1"/>
      <inertia ixx="0.2" ixy="0" ixz="0" iyy="0.2" iyz="0" izz="0.2"/>
    </inertial>
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <cylinder length="0.086" radius="0.11"/>
      </geometry>
    </visual>
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <cylinder length="0.086" radius="0.11"/>
      </geometry>
    </collision>
  </link>
  <joint name="wheel_0_joint" type="continuous">
    <parent link="base_link"/>
    <child link="wheel_0_link"/>
    <origin rpy="-1.5707963267948966 0 0" xyz="0.3 0 0"/>
    <axis xyz="0 0 1"/>
  </joint>
  <!-- Transmission is important to link the joints and the controller -->
  <transmission name="wheel_0_joint_trans" type="SimpleTransmission">
    <actuator name="wheel_0_joint_motor"/>
    <joint name="wheel_0_joint"/>
    <mechanicalReduction>1</mechanicalReduction>
    <motorTorqueConstant>1</motorTorqueConstant>
  </transmission>
  <gazebo reference="wheel_0_link">
    <material>Gazebo/Red</material>
  </gazebo>
  <link name="wheel_1_link">
    <inertial>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <mass value="1"/>
      <inertia ixx="0.2" ixy="0" ixz="0" iyy="0.2" iyz="0" izz="0.2"/>
    </inertial>
    <visual>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <cylinder length="0.086" radius="0.11"/>
      </geometry>
    </visual>
    <collision>
      <origin rpy="0 0 0" xyz="0 0 0"/>
      <geometry>
        <cylinder length="0.086" radius="0.11"/>
      </geometry>
    </collision>
  </link>
  <joint name="wheel_1_joint" type="continuous">
    <parent link="base_link"/>
    <child link="wheel_1_link"/>
    <origin rpy="-1.5707963267948966 0 0" xyz="-0.2 0 0"/>
    <axis xyz="0 0 1"/>
  </joint>
  <!-- Transmission is important to link the joints and the controller -->
  <transmission name="wheel_1_joint_trans" type="SimpleTransmission">
    <actuator name="wheel_1_joint_motor"/>
    <joint name="wheel_1_joint"/>
    <mechanicalReduction>1</mechanicalReduction>
    <motorTorqueConstant>1</motorTorqueConstant>
  </transmission>
  <gazebo reference="wheel_1_link">
    <material>Gazebo/Red</material>
  </gazebo>
  <!-- Colour -->
  <gazebo reference="base_link">
    <material>Gazebo/Green</material>
  </gazebo>
  <gazebo reference="base_footprint">
    <material>Gazebo/Purple</material>
  </gazebo>
  <ros2_control name="TestActuatorHardwareLeft" type="actuator">
    <hardware>
      <plugin>test_actuator</plugin>
    </hardware>
    <joint name="wheel_left">
      <state_interface name="position"/>
      <command_interface name="velocity"/>
      <state_interface name="velocity"/>
    </joint>
  </ros2_control>
  <ros2_control name="TestActuatorHardwareRight" type="actuator">
    <hardware>
      <plugin>test_actuator</plugin>
    </hardware>
    <joint name="wheel_right">
      <state_interface name="position"/>
      <command_interface name="velocity"/>
      <state_interface name="velocity"/>
    </joint>
  </ros2_control>
</robot>
)";

}  // namespace diff_drive_controller_testing

#endif  // TEST_COMMON_HPP_
