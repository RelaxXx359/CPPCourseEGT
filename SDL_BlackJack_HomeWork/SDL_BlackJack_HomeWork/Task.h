﻿//Правила:
//
//Блекджек се играе с няколко тестета карти.Целта на играта е ръката на играча да победи ръката на дилъра,
//  като сумата на ръката на играча не надвишава 21 точки.Асото се брои за 1 или 11 точки.Вале, Дама, Поп са по 10 точки,
//  останалите карти - колкото е написано на тях;
//
//Изисквания:
//
//В началото на играта се избира произволна бройка тестетата които да се ползват(4, 6 или 8);
//Дилъра играе срещу 1 играч;
//Началният капитал на играча е $100 000;
//Играча избира нисък или висок залог($100 или $1000);
//Дилъра дава 1 карта с лицето нагоре на играча и една с лицето на долу за себе си,
//  след това дава по още една карта с лицето нагоре на играча и на себе си;
//По екрана се изписва текущия резултат на играча
//Има 2 бутона: (hit, stay); 7.1.Ако играча избере hit - получава още една карта, резултата се ъпдейтва, ако надвиши 21, губи рунда;
//  7.2 Ако играча избере stay - играча остава с резултата, който има;
//Ако играча е под 21 точки, дилъра обръща обърнатата си карта и започва да си дава карти докато не подобри резултата на играча,
//  или стигне 21, или надмине 21 (резултатът на дилъра също се показва на екрана);
//След края на рунда; 9.1 Ако играча спечели ръката, печели толкова, колкото е заложил(+връща си каквото е заложил);
//  9.2.Ако играча спечели ръката с 21 точки, получава 1.5 пъти заложените пари(+връща си каквото е заложил); 
// 9.3.Ако играча загуби ръката, губи това което е заложил;
//Ако играча остане с $0 губи играта и играта свършва;
//Играча може да спре играта по всяко време(между рундовете) и парите които има се запазват.
//Звук; 12.1 Звук при раздаването на карти; 12.2 Звук при избирането на hit и stay; 12.3 Звук при загуба на играта; 12.4 Звук при спиране на играта;