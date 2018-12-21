


gripper=robotics.RigidBodyTree('MaxNumBodies',4, 'Dataformat', 'column');
L1=0.3;
L2=0.3;
L3=0.25;

DHParams1=[ 0.3/2,pi,0,0; 
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
joint.JointAxis=[0 0 1];
body1.Joint= joint;
addBody(gripper,body1, 'palm1');

body2 = robotics.RigidBody('MittelPhalanx1');
joint = robotics.Joint('PIPJoint1','revolute');
joint.HomePosition=0;
setFixedTransform(joint, DHParams1(3,:),'dh');
joint.JointAxis=[0 0 1];
body2.Joint= joint;
addBody(gripper, body2, 'GrundPhalanx1');

body2 = robotics.RigidBody('EndPhalanx1');
joint = robotics.Joint('DIPJoint1','revolute');
joint.HomePosition=0;
setFixedTransform(joint, DHParams1(4,:),'dh');
joint.JointAxis=[0 0 1];
body2.Joint= joint;
addBody(gripper, body2, 'MittelPhalanx1');


DHParams2=[ 0.35/2,0,0,pi; 
    L1,0,0,pi;
    L2,0,0,pi; 
    L3,0,0,pi];

body0=robotics.RigidBody('palm2');
joint=robotics.Joint('BaseJoint2');
setFixedTransform(joint,DHParams2(1,:),'dh');
body0.Joint= joint;
addBody(gripper,body0, 'base');

body1=robotics.RigidBody('GrundPhalanx2');
joint=robotics.Joint('MCPJoint2', 'revolute');
%joint.HomePosition=pi/2-pi/8;
setFixedTransform(joint, DHParams2(2,:),'dh');
joint.JointAxis=[0 0 1];
body1.Joint= joint;
addBody(gripper,body1, 'palm2');

body2 = robotics.RigidBody('MittelPhalanx2');
joint = robotics.Joint('PIPJoint2','revolute');
joint.HomePosition=0;
setFixedTransform(joint, DHParams2(3,:),'dh');
joint.JointAxis=[0 0 1];
body2.Joint= joint;
addBody(gripper, body2, 'GrundPhalanx2');

body2 = robotics.RigidBody('EndPhalanx2');
joint = robotics.Joint('DIPJoint2','revolute');
joint.HomePosition=0;
setFixedTransform(joint, DHParams2(4,:),'dh');
joint.JointAxis=[0 0 1];
body2.Joint= joint;
addBody(gripper, body2, 'MittelPhalanx2');

config=homeConfiguration(gripper)

figure;

show(gripper);
hold on;


% %%%%%%%%%%%%%%%%%%%%%%%%%%%lateralprecision
% for i = 0:2:10
% 
%     n=i*(pi/180);
%     configlateralpr=[(pi/2+n);0; 0;(pi/2+n);0;0];
%     show(gripper,configlateralpr);
%     hold on;
% end


%%%%%%%%%%%%%%%%%%%%%%%%%%%lateralpower
% for i = 0:30:90
% 
%     n=i*(pi/180);
%     
%     configlateralpower1=[0;n; (pi/2-n);0;n;(pi/2-n)];
%     %show(gripper,configlateralpower1);
%     hold on;
%     configlateralpower2=[n; (pi/2-n);0;n;(pi/2-n);0];
%     show(gripper,configlateralpower2);
%     hold on;
%     
% end

% %%%%%%%%%%%%%%%%%%%%%%%%%%%cylindircalpower
% for i = 30:10:80
%     
%     n=i*(pi/180);
%     configzylindircalPower=[n;n;n;n;n;n];
%     show(gripper,configzylindircalPower);
%     hold on;
%     
% end

% % %%%%%%%%%%%%%%%%%%%%%%%%%%%cylindircalprecision
% for i = 0:2:6
%     
%     n=i*(pi/180);
%     configzylindircalPr=[(pi/4)+n;(pi/4)+n; (pi/4)+n;(pi/4)+n;(pi/4)+n; +(pi/4)+n];
%     show(gripper,configzylindircalPr);
% 
% end

showdetails(gripper)





%configlateral1=[-pi/2;0;0;pi/2;0;0];
%show(gripper,configlateral1);
 

%tform = getTransform(gripper,configlateral1,'EndPhalanx1','base')

%configlateral2=[0;-pi/2;0;0;pi/2;0];
%show(gripper,configlateral2);
%tform = getTransform(gripper,configlateral2,'EndPhalanx1','base')
 














