Chat.log("Started......");
function sleep(milliseconds) {
    const start = new Date().getTime();
    let now = start;
    while (now - start < milliseconds) {
        now = new Date().getTime();
    }
}
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
Chat.log("Success___the loop will continue forever..........");
  for (let i = 0; i < 64; i++) {
    inv.click(0);
    sleep(12);
  }
  inv.click(1);
  var count = 99999;
  while (count--) {
    sball.craft(true);
    var limit=1000;
    while((inv.getSlot(0).getName().getString()!="Slimeball")&& limit--){sleep(5);}
    //sleep(15);
    inv.quick(0);
    sblock.craft(true);
    var stack = 64;
    while (stack--) {
      inv.click(0);
      sleep(12);
    }
    inv.click(1);
  }