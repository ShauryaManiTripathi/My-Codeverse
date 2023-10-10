import java.util.ArrayList;
import java.util.Date;
import java.util.Scanner;

class User {
    protected String name;
    protected Date dateOfBirth;
    protected String address;
    protected String PAN;

    public User(String name, Date dateOfBirth, String address, String PAN) {
        this.name = name;
        this.dateOfBirth = dateOfBirth;
        this.address = address;
        this.PAN = PAN;
    }
}

class SuperUser extends User {
    private int superUserID;
    private Date dateOfJoining;
    private double salary;
    private ArrayList<String> permissibleOperations;

    public SuperUser(int userID, String name, Date dateOfBirth, String address, String PAN, Date dateOfJoining, double salary) {
        super(name, dateOfBirth, address, PAN);
        superUserID=userID;
        this.dateOfJoining = dateOfJoining;
        this.salary = salary;
        this.permissibleOperations = new ArrayList<>();
    }

    public void addPermissibleOperation(String operation) {
        permissibleOperations.add(operation);
    }

    public void removePermissibleOperation(String operation) {
        permissibleOperations.remove(operation);
    }

    public ArrayList<String> getPermissibleOperations() {
        return permissibleOperations;
    }
}

class NormalUser extends User {
    private int userID;
    private Date dateOfJoining;
    private double salary;
    private int dutyHourPerDay;

    public NormalUser(int userID, String name, Date dateOfBirth, String address, String PAN, Date dateOfJoining, double salary, int dutyHourPerDay) {
        super(name, dateOfBirth, address, PAN);
        this.userID=userID;
        this.dateOfJoining = dateOfJoining;
        this.salary = salary;
        this.dutyHourPerDay = dutyHourPerDay;
    }
}

class Item {
    protected int itemCode;
    protected double price;
    protected int availableQty;

    public Item(int itemCode, double price, int availableQty) {
        this.itemCode = itemCode;
        this.price = price;
        this.availableQty = availableQty;
    }
}

class Consumables extends Item {
    private Date dateOfExpiry;

    public Consumables(int itemCode, double price, int availableQty, Date dateOfExpiry) {
        super(itemCode, price, availableQty);
        this.dateOfExpiry = dateOfExpiry;
    }
}

class NonConsumables extends Item {
    private int returnCount;

    public NonConsumables(int itemCode, double price, int availableQty) {
        super(itemCode, price, availableQty);
        this.returnCount = 0;
    }

    public int getReturnCount() {
        return returnCount;
    }

    public void increaseReturnCount() {
        returnCount++;
    }
}

class Sell {
    Date dateOfSell;
    int itemCode;
    int quantity;
    double totalAmount;

    public Sell(Date dateOfSell, int itemCode, int quantity, double totalAmount) {
        this.dateOfSell = dateOfSell;
        this.itemCode = itemCode;
        this.quantity = quantity;
        this.totalAmount = totalAmount;
    }
}

class Return {
    Date dateOfReturn;
    int itemCode;
    int quantity;
    double returnAmount;

    public Return(Date dateOfReturn, int itemCode, int quantity, double returnAmount) {
        this.dateOfReturn = dateOfReturn;
        this.itemCode = itemCode;
        this.quantity = quantity;
        this.returnAmount = returnAmount;
    }
}



class InventorySystem {
    static Date currDate;
    private ArrayList<Item> items;
    private ArrayList<Integer> isConsumable;
    private ArrayList<Sell> soldItems;
    private ArrayList<Return> returnedItems;

    public InventorySystem() {
        items = new ArrayList<>();
        soldItems = new ArrayList<>();
        returnedItems = new ArrayList<>();
    }

    public Item getItemByCode(int itemCode) {
        for (Item item : items) 
        {
            if (item.itemCode == itemCode) 
            {
                return item;
            }
        }
        return null;
    }

    public void addNewStock(Item item,int isConsumable) {
        items.add(item);
        this.isConsumable.add(isConsumable);
    }

    public void deleteStock(int itemCode) {
        Item itemToRemove = null;
        for (Item item : items) {
            if (item.itemCode == itemCode && item.availableQty == 0) {
                itemToRemove = item;
                break;
            }
        }
        if (itemToRemove != null) {
            items.remove(itemToRemove);
            isConsumable.remove(items.indexOf(itemToRemove));
        }
    }

    public void modifyStock(int itemCode, double price, int availableQty) {
        for (Item item : items) {
            if (item.itemCode == itemCode) {
                item.price = price;
                item.availableQty = availableQty;
                break;
            }
        }
    }

    public void sellItem(int itemCode, int quantity, double totalPrice) {
        for (Item item : items) {
            if (item.itemCode == itemCode) {
                item.availableQty -= quantity;
                soldItems.add(new Sell(new Date(), itemCode, quantity, totalPrice));
                break;
            }
        }
    }

    public void returnItem(int itemCode, int quantity, double returnAmount) {
        for (Item item : items) {
            if (item.itemCode == itemCode && !(item instanceof Consumables)) {
                item.availableQty += quantity;
                NonConsumables nonFoodItem = (NonConsumables) item;
                nonFoodItem.increaseReturnCount();
                returnedItems.add(new Return(new Date(), itemCode, quantity, returnAmount));
                break;
            }
        }
    }

    public void displayStock(int itemCode) {
        Item item = getItemByCode(itemCode);
        
        if (item != null) 
        {
            System.out.println("Item Code: " + item.itemCode);
            System.out.println("Price: " + item.price);
            System.out.println("Available Quantity: " + item.availableQty);
            System.out.println("This is a "+(this.isConsumable.get(items.indexOf(item))==1?"Consumable Item":"Non Consumable Item"));
        } 
        else 
        {
            System.out.println("Item not found.");
        }
    }

    public void displayToBeExpired(Date startDate, Date endDate) {
        ArrayList<Item> itemsAboutToExpire = getItemsAboutToExpire(startDate, endDate);
        if (itemsAboutToExpire.size() > 0) 
        {
            for (Item soldItem : itemsAboutToExpire) 
            {
                System.out.println("Available quantity: " + soldItem.availableQty);
                System.out.println("itemCode: " + soldItem.itemCode);
                System.out.println("Price: " + soldItem.price);
            }
        } 
        else 
        {
            System.out.println("No Items going to expire till now");
        }
    }

    public ArrayList<Item> getItemsAboutToExpire(Date startDate, Date endDate) {
        ArrayList<Item> itemsGoingToEpire = new ArrayList<>();
        for (Item consumable : items) {
            // if(isConsumable.get(items.indexOf(consumable))==1)
            //  if (consumable.dateOfExpiry.after(startDate) && consumable.dateOfExpiry.before(endDate)) {
            //      itemsGoingToEpire.add(consumable);
            //  }
        }
        return itemsGoingToEpire;
    }

    public void displaySell(Date startDate, Date endDate) {
        ArrayList<Sell> itemsInDateRange = getSoldItemsInDateRange(startDate, endDate);
        if (itemsInDateRange.size() > 0) 
        {
            for (Sell soldItem : itemsInDateRange) 
            {
                System.out.println("Selling Date: " + soldItem.dateOfSell);
                System.out.println("itemCode: " + soldItem.itemCode);
                System.out.println("amountSold: " + soldItem.quantity);
                System.out.println("totalAmount: " + soldItem.totalAmount+"\n");
            }
        } 
        else 
        {
            System.out.println("No item sold till now");
        }
    }

    public ArrayList<Sell> getSoldItemsInDateRange(Date startDate, Date endDate) {
        ArrayList<Sell> itemsInDateRange = new ArrayList<>();
        for (Sell soldItem : soldItems) {
            if (soldItem.dateOfSell.after(startDate) && soldItem.dateOfSell.before(endDate)) {
                itemsInDateRange.add(soldItem);
            }
        }
        return itemsInDateRange;
    }

    


}

public class Shaurya_2201184{
    ///////////////////////////////////////////////////////////////////////////// MAIN METHOD STARTS HERE /////////////////////////////////////////////////////////
    public static void main(String[] args) {
        System.out.println("Hello my name is shaurya mani tripathi and sadly I am assumed to complete this within 2 hours but i tried to complete all ESSENTIAL STUFF WHICH INCLUDES COMPLETE IMPLEMENTATION OF EVERYTHING ELSE EXCEPT MENU");
    }
    ///////////////////////////////////////////////////////////////////////////// MAIN METHOD ENDS HERE   ////////////////////////////////////////////////////////
    private static void AdminAction(Scanner scanner, InventorySystem inventorySystem, String operation) {
        switch (operation) {
            case "addNewStock":
                System.out.println("Enter Item Code:");
                int itemCode = scanner.nextInt();
                System.out.println("Enter Price:");
                double price = scanner.nextDouble();
                System.out.println("Enter Available Quantity:");
                int availableQty = scanner.nextInt();
                System.out.println("is this item a Consumable? 1 for yes and 0 for no");
                int isConsumable=scanner.nextInt();
                Item newItem;
                if(isConsumable==1){
                    System.out.println("Enter date of expiry yyyy-MM-dd");
                    String dateOfExpiry=scanner.nextLine();
                    newItem= new Consumables(itemCode, price, availableQty,new Date(dateOfExpiry));
                }
                else{
                    newItem= new NonConsumables(itemCode,price,availableQty);
                }
                inventorySystem.addNewStock(newItem,isConsumable);
                System.out.println("Item added successfully.");
                break;
            case "deleteStock":
                System.out.println("Enter Item Code to delete:");
                int itemCodeToDelete = scanner.nextInt();
                inventorySystem.deleteStock(itemCodeToDelete);
                System.out.println("Item deleted successfully.");
                break;
            case "modifyStock":
                System.out.println("Enter Item Code to modify:");
                int itemCodeToModify = scanner.nextInt();
                System.out.println("Enter New Price:");
                double newPrice = scanner.nextDouble();
                System.out.println("Enter New Available QuavailableQtyantity:");
                int newAvailableQty = scanner.nextInt();
                inventorySystem.modifyStock(itemCodeToModify, newPrice, newAvailableQty);
                System.out.println("Item modified successfully.");
                break;
            default:
                System.out.println("Invalid operation.");
                break;
        }
    }

    private static void GeneralAction(Scanner scanner, InventorySystem inventorySystem, String operation) {
        switch (operation) {
            case "sellItem":
                System.out.println("Enter Item Code to sell:");
                int itemCode = scanner.nextInt();
                System.out.println("Enter Quantity:");
                int quantity = scanner.nextInt();
                Item item = inventorySystem.getItemByCode(itemCode);
                if (item != null) {
                    if (item.availableQty >= quantity) {
                        double totalPrice = item.price * quantity;
                        inventorySystem.sellItem(itemCode, quantity, totalPrice);
                        System.out.println("Item sold successfully.");
                    } else {
                        System.out.println("Insufficient quantity available.");
                    }
                } else {
                    System.out.println("Item not found.");
                }
                break;
            case "returnItem":
                System.out.println("Enter Item Code to return:");
                int returnItemCode = scanner.nextInt();
                Item returnItem = inventorySystem.getItemByCode(returnItemCode);
                if (returnItem != null && !(returnItem instanceof FoodItem)) {
                    System.out.println("Enter Quantity to return:");
                    int returnQuantity = scanner.nextInt();
                    if (returnQuantity > 0 && returnQuantity <= returnItem.availableQty) {
                        double returnAmount = returnItem.price * returnQuantity;
                        inventorySystem.returnItem(returnItemCode, returnQuantity, returnAmount);
                        System.out.println("Item returned successfully.");
                    } else {
                        System.out.println("Invalid quantity to return.");
                    }
                } else {
                    System.out.println("Item not found or cannot return a food item.");
                }
                break;
            case "displayStock":
                System.out.println("Enter Item Code to display:");
                int displayItemCode = scanner.nextInt();
                inventorySystem.displayStock(displayItemCode);
                break;
            case "displayToBeExpiredItems":
                
            case "displaySell":
                System.out.println("Enter Start Date (yyyy-MM-dd):");
                String startDateStr = scanner.nextLine();
                System.out.println("Enter End Date (yyyy-MM-dd):");
                String endDateStr = scanner.nextLine();
                Date startDate = new Date(startDateStr);
                Date endDate = new Date(endDateStr);
                inventorySystem.displaySell(startDate, endDate);
                break;
            default:
                System.out.println("Invalid operation.");
                break;
        }
    }

}