# main python code

from fare import calculate_passenger_fare, apply_promo
from routes import ROUTES, TRAIN_TYPES, CLASSES

def print_menu(options, title):
    # for displaying numbered menu
    print(f"\n{title}:")
    for key, value in options.items():
        print(f"{key}. {value['name']}")
    print()

def get_valid_int(prompt, min_val=1, max_val=None, allow_zero=False):
    # get validated integer input
    while True:
        try:
            value = int(input(prompt))
            if allow_zero and value >= 0 or value >= min_val:
                if max_val is None or value <= max_val:
                    return value
                print(f"Please enter a number between {min_val} and {max_val}.")
            elif not allow_zero:
                print(f"Please enter a valid number (>= {min_val}).")
            else:
                print("Please enter a valid non-negative number.")
        except ValueError:
            print("Please enter a valid number.")

def get_valid_float(prompt, min_val=0):
    #get validated float input for baggage
    while True:
        try:
            value = float(input(prompt))
            if value >= min_val:
                return round(value, 1)
            print(f"Please enter a valid number (>= {min_val}).")
        except ValueError:
            print("Please enter a valid number.")

def display_route_menu():
    #get route selection
    print_menu(ROUTES, "Available Routes")
    route_num = get_valid_int("Select route number: ", 1, 9)
    return route_num, ROUTES[route_num]

def display_train_menu():
    # get train type selection
    print_menu(TRAIN_TYPES, "Train Types")
    train_num = get_valid_int("Select train type: ", 1, 3)
    return train_num

def display_class_menu():
    # get class selection
    print_menu(CLASSES, "Travel Classes")
    class_num = get_valid_int("Select class: ", 1, 3)
    return class_num

def get_passenger_details(num_passengers, route_distance, train_type, class_type):
    #get details for all passengers
    passengers = []
    
    for i in range(num_passengers):
        print(f"\n--- Passenger {i+1} ---")
        
        while True:
            age = get_valid_int(f"Enter age for passenger {i+1}: ", 1)
            baggage = get_valid_float(f"Enter baggage weight (kg) for passenger {i+1}: ", 0.1)
            
            fare_details = calculate_passenger_fare(
                route_distance, train_type, class_type, age, baggage
            )
            
            print(f"Fare breakdown for passenger {i+1}:")
            print(f"  Base slab fare: ₹{fare_details['slab_fare']}")
            print(f"  After senior discount: ₹{fare_details['after_discount']}")
            print(f"  After train premium: ₹{fare_details['after_train']}")
            print(f"  After class premium: ₹{fare_details['after_class']}")
            print(f"  Excess baggage ({fare_details['excess_baggage']}kg): ₹{fare_details['baggage_fee']}")
            print(f"  Surcharge: ₹{fare_details['surcharge']}")
            print(f"  TOTAL for this passenger: ₹{fare_details['final_fare']}")
            
            confirm = input("Is this correct? (y/n): ").lower()
            if confirm == 'y':
                passengers.append({
                    "age": age,
                    "baggage": baggage,
                    "fare_details": fare_details
                })
                break
            print("Please re-enter details.")
    
    return passengers

def main():
    print("=== INDIAN RAILWAY TICKET BOOKING SYSTEM ===\n")
    
    # route selection
    route_num, route_info = display_route_menu()
    distance = route_info["distance"]
    
    # train type
    train_num = display_train_menu()
    train_info = TRAIN_TYPES[train_num]
    
    #class selection
    class_num = display_class_menu()
    class_info = CLASSES[class_num]
    
    # number of passengers
    num_passengers = get_valid_int("Enter number of passengers: ", 1)
    
    # passenger details and fare calculation
    passengers = get_passenger_details(num_passengers, distance, train_num, class_num)
    
    # calculate subtotal
    subtotal = sum(p["fare_details"]["final_fare"] for p in passengers)
    
    #display summary before promo
    print("\n" + "="*60)
    print("TICKET SUMMARY")
    print("="*60)
    print(f"Route: {route_info['name']} ({distance} km)")
    print(f"Train: {train_info['name']}")
    print(f"Class: {class_info['name']}")
    print(f"Passengers: {num_passengers}")
    print(f"\nIndividual fares:")
    for i, p in enumerate(passengers, 1):
        print(f"  Passenger {i}: ₹{p['fare_details']['final_fare']}")
    print(f"\nSUBTOTAL: ₹{subtotal:.2f}")
    
    # promo code
    promo_code = input("\nEnter promo code (or press Enter to skip): ").strip().upper()
    if not promo_code:
        final_total = subtotal
        discount = 0
        promo_msg = "No promo code applied"
    else:
        final_total, discount, promo_msg = apply_promo(subtotal, promo_code)
    
    # final bill
    print("\n" + "="*60)
    print("FINAL BILL")
    print("="*60)
    print(f"SUBTOTAL: ₹{subtotal:.2f}")
    print(f"Discount: ₹{discount:.2f}")
    print(f"{promo_msg}")
    print(f"FINAL AMOUNT: ₹{final_total:.2f}")
    print("="*60)

if __name__ == "__main__":     # beacuse this is the main program file
    main()