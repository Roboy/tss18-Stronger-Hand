gripper=robotics.RigidBodyTree('MaxNumBodies',4, 'Dataformat', 'column');
L1=0.3;
L2=0.3;
L3=0.25;



DHParams1=[ 0.35/2,pi,0,0; 
    L1,0,0,0;
    L2,0,0,0; 
    L3,0,0,0];
    

body0=robotics.RigidBody('palm1');
joint=robotics.Joint('BaseJoint1');
setFixedTransform(joint,DHParams1(1,:),'dh');
body0.Joint= joint;
addBody(gripper,body0, 'base');

body1=robotics.RigidBody('GrundPhalanx1');
joint=robotics.Joint('MCPJoint1', 'revolute');
%joint.HomePosition=-(pi/2-pi/8);
setFixedTransform(joint, DHParams1(2,:),'dh');
joint.JointAxis=[0 1 0];
body1.Joint= joint;
addBody(gripper,body1, 'palm1');

body2 = robotics.RigidBody('MittelPhalanx1');
joint = robotics.Joint('PIPJoint1','revolute');
joint.HomePosition=0;
setFixedTransform(joint, DHParams1(3,:),'dh');
joint.JointAxis=[0 1 0];
body2.Joint= joint;
addBody(gripper, body2, 'GrundPhalanx1');

body2 = robotics.RigidBody('EndPhalanx1');
joint = robotics.Joint('DIPJoint1','revolute');
joint.HomePosition=0;
setFixedTransform(joint, DHParams1(4,:),'dh');
joint.JointAxis=[0 1 0];
body2.Joint= joint;
addBody(gripper, body2, 'MittelPhalanx1');


DHParams2=[ 0.35/2,pi,0,(2/3)*pi; 
    L1,0,0,(2/3)*pi;
    L2,0,0,(2/3)*pi; 
    L3,0,0,(2/3)*pi];



body0=robotics.RigidBody('palm2');
joint=robotics.Joint('BaseJoint2');
setFixedTransform(joint,DHParams2(1,:),'dh');
body0.Joint= joint;
addBody(gripper,body0, 'base');

body1=robotics.RigidBody('GrundPhalanx2');
joint=robotics.Joint('MCPJoint2', 'revolute');
%joint.HomePosition=pi/2-pi/8;
setFixedTransform(joint, DHParams2(2,:),'dh');
joint.JointAxis=[0 1 0];
body1.Joint= joint;
addBody(gripper,body1, 'palm2');

body2 = robotics.RigidBody('MittelPhalanx2');
joint = robotics.Joint('PIPJoint2','revolute');
joint.HomePosition=0;
setFixedTransform(joint, DHParams2(3,:),'dh');
joint.JointAxis=[0 1 0];
body2.Joint= joint;
addBody(gripper, body2, 'GrundPhalanx2');

body2 = robotics.RigidBody('EndPhalanx2');
joint = robotics.Joint('DIPJoint2','revolute');
joint.HomePosition=0;
setFixedTransform(joint, DHParams2(4,:),'dh');
joint.JointAxis=[0 1 0];
body2.Joint= joint;
addBody(gripper, body2, 'MittelPhalanx2');


DHParams3=[ 0.35/2,pi,0,(4/3)*pi; 
    L1,0,0,(4/3)*pi;
    L2,0,0,(4/3)*pi; 
    L3,0,0,(4/3)*pi];

body0=robotics.RigidBody('palm3');
joint=robotics.Joint('BaseJoint3');
setFixedTransform(joint,DHParams3(1,:),'dh');
body0.Joint= joint;
addBody(gripper,body0, 'base');

body1=robotics.RigidBody('GrundPhalanx3');
joint=robotics.Joint('MCPJoint3', 'revolute');
%joint.HomePosition=pi/2-pi/8;
setFixedTransform(joint, DHParams3(2,:),'dh');
joint.JointAxis=[0 1 0];
body1.Joint= joint;
addBody(gripper,body1, 'palm3');

body2 = robotics.RigidBody('MittelPhalanx3');
joint = robotics.Joint('PIPJoint3','revolute');
joint.HomePosition=0;
setFixedTransform(joint, DHParams3(3,:),'dh');
joint.JointAxis=[0 1 0];
body2.Joint= joint;
addBody(gripper, body2, 'GrundPhalanx3');

body2 = robotics.RigidBody('EndPhalanx3');
joint = robotics.Joint('DIPJoint3','revolute');
joint.HomePosition=0;
setFixedTransform(joint, DHParams3(4,:),'dh');
joint.JointAxis=[0 1 0];
body2.Joint= joint;
addBody(gripper, body2, 'MittelPhalanx3');

config=homeConfiguration(gripper)

figure;

show(gripper);
hold on;


%%%%%%%%%%%%%%%%%%%%%%%%%%%cylindircalpower
for i = 30:10:60
    
    n=i*(pi/180);
    configzylindircalPower=[n;n; n;n;n;n;n;n; n];
    show(gripper,configzylindircalPower);
    hold on;
    
end

% % %%%%%%%%%%%%%%%%%%%%%%%%%%%cylindircalprecision
% for i = 0:2:6
%     
%     n=i*(pi/180);
%     configzylindircalPr=[(pi/4)+n;(pi/4)+n; (pi/4)+n;(pi/4)+n;(pi/4)+n;(pi/4)+n;(pi/4)+n;(pi/4)+n; (pi/4)+n];
%     show(gripper,configzylindircalPr);
% 
% end


showdetails(gripper)