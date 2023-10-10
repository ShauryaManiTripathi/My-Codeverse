import java.util.ArrayList;
import java.util.Date;
import java.util.Scanner;

class User {
    protected int userID;
    protected String name;
    protected Date dateOfBirth;
    protected String address;
    protected String PAN;

    public User(int userID, String name, Date dateOfBirth, String address, String PAN) {
        this.userID = userID;
        this.name = name;
        this.dateOfBirth = dateOfBirth;
        this.address = address;
        this.PAN = PAN;
    }
}

class Admin extends User {
    private Date dateOfJoining;
    private double salary;
    private ArrayList<String> permissibleOperations;

    public Admin(int userID, String name, Date dateOfBirth, String address, String PAN, Date dateOfJoining, double salary) {
        super(userID, name, dateOfBirth, address, PAN);
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

class General extends User {
    private Date dateOfJoining;
    private double salary;
    private int dutyHourPerDay;

    public General(int userID, String name, Date dateOfBirth, String address, String PAN, Date dateOfJoining, double salary, int dutyHourPerDay) {
        super(userID, name, dateOfBirth, address, PAN);
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

class FoodItem extends Item {
    private Date dateOfExpiry;

    public FoodItem(int itemCode, double price, int availableQty, Date dateOfExpiry) {
        super(itemCode, price, availableQty);
        this.dateOfExpiry = dateOfExpiry;
    }
}

class NonFoodItem extends Item {
    private int returnCount;

    public NonFoodItem(int itemCode, double price, int availableQty) {
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
    public  Date dateOfSell;
    public  int itemCode;
    public  int quantity;
    public  double totalAmount;

    public Sell(Date dateOfSell, int itemCode, int quantity, double totalAmount) {
        this.dateOfSell = dateOfSell;
        this.itemCode = itemCode;
        this.quantity = quantity;
        this.totalAmount = totalAmount;
    }
}

class Return {
    private Date dateOfReturn;
    private int itemCode;
    private int quantity;
    private double returnAmount;

    public Return(Date dateOfReturn, int itemCode, int quantity, double returnAmount) {
        this.dateOfReturn = dateOfReturn;
        this.itemCode = itemCode;
        this.quantity = quantity;
        this.returnAmount = returnAmount;
    }
}

class InventorySystem {
    private ArrayList<Item> items;
    private ArrayList<Sell> soldItems;
    private ArrayList<Return> returnedItems;

    public InventorySystem() {
        items = new ArrayList<>();
        soldItems = new ArrayList<>();
        returnedItems = new ArrayList<>();
    }

    public void addNewStock(Item item) {
        items.add(item);
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
            if (item.itemCode == itemCode && !(item instanceof FoodItem)) {
                item.availableQty += quantity;
                NonFoodItem nonFoodItem = (NonFoodItem) item;
                nonFoodItem.increaseReturnCount();
                returnedItems.add(new Return(new Date(), itemCode, quantity, returnAmount));
                break;
            }
        }
    }

    public Item getItemByCode(int itemCode) {
        for (Item item : items) {
            if (item.itemCode == itemCode) {
                return item;
            }
        }
        return null;
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

    public void displayStock(int itemCode) {
        Item item = getItemByCode(itemCode);
        if (item != null) {
            System.out.println("Item Code: " + item.itemCode);
            System.out.println("Price: " + item.price);
            System.out.println("Available Quantity: " + item.availableQty);
        } else {
            System.out.println("Item not found.");
        }
    }

    public void displaySell(Date startDate, Date endDate) {
        ArrayList<Sell> itemsInDateRange = getSoldItemsInDateRange(startDate, endDate);
        if (itemsInDateRange.size() > 0) {
            for (Sell soldItem : itemsInDateRange) {
                System.out.println("Date of Sale: " + soldItem.dateOfSell);
                System.out.println("Item Code: " + soldItem.itemCode);
                System.out.println("Quantity Sold: " + soldItem.quantity);
                System.out.println("Total Amount: " + soldItem.totalAmount);
                System.out.println();
            }
        } else {
            System.out.println("No items sold in the specified date range.");
        }
    }
}

public class InventoryManagementApp {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Welcome to Inventory Management App!");

        // Create an instance of InventorySystem
        InventorySystem inventorySystem = new InventorySystem();

        // Sample Admin and General users
        Admin adminUser = new Admin(1, "AdminUser", new Date(), "Address1", "ABC123", new Date(), 50000);
        General generalUser = new General(2, "GeneralUser", new Date(), "Address2", "XYZ789", new Date(), 25000, 8);

        // Add permissible operations for Admin user
        adminUser.addPermissibleOperation("addNewStock");
        adminUser.addPermissibleOperation("deleteStock");
        adminUser.addPermissibleOperation("modifyStock");

        System.out.println("Select User Type (Admin/General):");
        String userType = scanner.nextLine();

        while (true) {
            if (userType.equalsIgnoreCase("Admin")) {
                System.out.println("Enter Admin Username:");
                String username = scanner.nextLine();
                if (username.equals(adminUser.name)) {
                    System.out.println("Logged in as Admin.");
                    System.out.println("Available Operations: " + adminUser.getPermissibleOperations());
                    System.out.println("Enter Operation (or type 'exit' to quit):");
                    String operation = scanner.nextLine();
                    if (operation.equalsIgnoreCase("exit")) {
                        break;
                    } else if (adminUser.getPermissibleOperations().contains(operation)) {
                        executeAdminOperation(scanner, inventorySystem, operation);
                    } else {
                        System.out.println("Operation not permitted.");
                    }
                } else {
                    System.out.println("Invalid username.");
                }
            } else if (userType.equalsIgnoreCase("General")) {
                System.out.println("Enter General Username:");
                String username = scanner.nextLine();
                if (username.equals(generalUser.name)) {
                    System.out.println("Logged in as General.");
                    System.out.println("Available Operations: sellItem, returnItem, displayStock, displaySell");
                    System.out.println("Enter Operation (or type 'exit' to quit):");
                    String operation = scanner.nextLine();
                    if (operation.equalsIgnoreCase("exit")) {
                        break;
                    } else {
                        executeGeneralOperation(scanner, inventorySystem, operation);
                    }
                } else {
                    System.out.println("Invalid username.");
                }
            } else {
                System.out.println("Invalid user type. Please enter 'Admin' or 'General'.");
            }
        }

        scanner.close();
    }

    private static void executeAdminOperation(Scanner scanner, InventorySystem inventorySystem, String operation) {
        switch (operation) {
            case "addNewStock":
                System.out.println("Enter Item Code:");
                int itemCode = scanner.nextInt();
                System.out.println("Enter Price:");
                double price = scanner.nextDouble();
                System.out.println("Enter Available Quantity:");
                int availableQty = scanner.nextInt();
                Item newItem = new Item(itemCode, price, availableQty);
                inventorySystem.addNewStock(newItem);
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
                System.out.println("Enter New Available Quantity:");
                int newAvailableQty = scanner.nextInt();
                inventorySystem.modifyStock(itemCodeToModify, newPrice, newAvailableQty);
                System.out.println("Item modified successfully.");
                break;
            default:
                System.out.println("Invalid operation.");
                break;
        }
    }

    private static void executeGeneralOperation(Scanner scanner, InventorySystem inventorySystem, String operation) {
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
            case "displaySell":
                System.out.println("Enter Start Date (yyyy-MM-dd):");
                String startDateStr = scanner.next();
                System.out.println("Enter End Date (yyyy-MM-dd):");
                String endDateStr = scanner.next();
                Date startDate = new Date();
                Date endDate = new Date();
                // Parse start and end dates (you can use SimpleDateFormat for this)
                // Set startDate and endDate accordingly
                inventorySystem.displaySell(startDate, endDate);
                break;
            default:
                System.out.println("Invalid operation.");
                break;
        }
    }
}