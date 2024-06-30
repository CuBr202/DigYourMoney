# DigYourMoney
欢迎来到Dig Your Money小游戏！
这是一个轻松的放置类小游戏，灵感来源于4399里的同类游戏，外观朴实但是绝对好玩！


## 游戏规则

### 游戏资源
钱币（自动产出，也可点击产出） 
铁，金，钻石（夺宝有概率产出，用于升级镐子）
红宝石（夺宝有小概率产出，用于短时间加速钱币产出，需手动使用）
蓝宝石，绿宝石（夺宝有小概率产出，用于永久加速钱币产出，无需手动使用）

### 标题
New Game为新游戏
Continue为读取上一次存档接着游戏
游戏主界面
左上为现有资源持有量
右上为钱币持有量以及每0.1s钱币生产量(IncomeSpeed)
IncomeSpeed=speedBase(基础速度，初始为5) x speedMult(速度乘区，初始为1) 
钱币以特殊科学计数法表示，保留3位小数，k,m,g,t,p,e分别表示10e3,10e6,10e9,10e12,10e15,10e18(如1.145m表示约1145000)
每点击一次Hit可以立即获得IncomeSpeed/5的钱币数
按Upgrade键可以花费资源升级虚拟镐子（用于夺宝）
按Speed Up！键可以立即消耗一个红宝石，在10s内将钱币产速暂时提高至原来的10倍
按Gamble可以进入夺宝界面

### 夺宝界面
夺宝界面是由8x12方块构成的矩阵
有3种方块：Dirt（硬度12），Stone（硬度36），Bedrock（硬度144）
基础镐子耐久30点（Unbreaking升级为0时），每次点击削减方块1点硬度（Speed升级为0时）
将Unbreaking升级为1，2，3级可以将镐子耐久提升至40，60，120点
将Speed升级为1，2，3级可以使至每次点击削减方块硬度提升至2，3，4点
注意：点击一次固定消耗镐子耐久1点，与削减方块的硬度无关
破坏方块后可能会获得1个或多个铁，金，钻石，红宝石，蓝宝石，绿宝石，也有可能什么都没有
铁，金，钻石用于镐子升级，红宝石用于短时间加速
蓝宝石会将当前钱币生产量永久提高1.2倍
绿宝石会将基础速度永久加5
越硬的方块获得资源的概率越大


## 具体数据

### Unbreaking升级
lv.1 10k钱+2铁
lv.2 1m钱+10铁+5金
lv.3 100m钱+50铁+20金+5钻石

### Speed升级
lv.1 10k钱+2金
lv.2 1m钱+5铁+10金
lv.3 100m钱+5铁+10金+20钻石

### 宝物产出概率

|         |   Dirt  |  Stone  | Bedrock |
| :-----: | :-----: | :-----: | :-----: |
| 无宝物   |  0.80 |   0.50    |  0.10  |
| 铁       |  0.10 |   0.20    |  0.30  |
| 金       |  0.05 |   0.10    |  0.20  |
| 钻石     |  0.02 |   0.08    |  0.10  |
| 蓝宝石   |  0.01 |   0.04    |  0.10  |
| 红宝石   |  0.01 |   0.04    |  0.10  |
| 绿宝石   |  0.01 |   0.04    |  0.10  |
每个方块概率完全独立，不能保证一张图中一定有某种宝物

### 产出宝物数量
|         |   Dirt  |  Stone  | Bedrock |
| :-----: | :-----: | :-----: | :-----: |
| 铁       |  0~2 |   0~4    |  0~10  |
| 金       |  0~1 |   0~2    |  0~5   |
| 钻石     |  0~1 |   0~1    |  0~3   |
| 蓝宝石   |  0~1 |   0~1    |  0~1   | 
| 红宝石   |  0~1 |   0~1    |  0~1   |
| 绿宝石   |  0~1 |   0~1    |  0~1   |
一个方块最多产出一种宝物





