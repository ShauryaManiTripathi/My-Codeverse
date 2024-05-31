// WORKING MACRO TEMPLATE FOR AUTO CRAFTING OF OAK PLANKS
// REQUIRES OAK LOGS INSIDE INVENTORY TO WORK

//step 1; if you need crafting table uncomment
const inv = Player.openInventory();
const recps = inv.getRecipes(false);
// step 2. log it to check
// step 3. loop to find the right one
var sblock = 0;
var sball = 0;
for (const recp of recps) {
  if (recp.getId() == "minecraft:slime_block") {
    // select it, true to put max into crafting table
    recp.craft(true);
    sblock = recp;
  }
  if (recp.getId() == "minecraft:slime_ball") {
    sball = recp;
  }
}
//step 4. move the output of crafting into inv

function a() {
  for (let i = 0; i < 64; i++) {
    inv.click(0);
  }
  var count = 10;
  while (count--) {
    sball.craft(true);
    inv.quick(0);
    sblock.craft(true);
    var stack = 64;
    while (stack--) {
      inv.click(0);
    }
    inv.click(10);
  }
}