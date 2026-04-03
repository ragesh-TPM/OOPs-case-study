# this file is for fixing the routes before the main program runs

# Fixed routes with distances in km using dictionary datatype
ROUTES = {
    1: {"name": "Delhi - Mumbai", "distance": 1380},
    2: {"name": "Delhi - Kolkata", "distance": 1465},
    3: {"name": "Delhi - Chennai", "distance": 2180},
    4: {"name": "Mumbai - Kolkata", "distance": 1970},
    5: {"name": "Mumbai - Chennai", "distance": 1290},
    6: {"name": "Kolkata - Chennai", "distance": 1655},
    7: {"name": "Delhi - Bangalore", "distance": 2115},
    8: {"name": "Mumbai - Delhi", "distance": 1380},
    9: {"name": "Chennai - Kolkata", "distance": 1655}
}

# Train types with speed kmph and also with premium multiplier
TRAIN_TYPES = {
    1: {"name": "Fast Passenger", "speed": 60, "premium": 1.0, "surcharge": 0},
    2: {"name": "Express", "speed": 80, "premium": 1.25, "surcharge": 50},
    3: {"name": "Superfast", "speed": 100, "premium": 1.5, "surcharge": 100}
}

# Travel classes with multiplier with baggage allowance
CLASSES = {
    1: {"name": "Sleeper", "multiplier": 1.0, "baggage": 20},
    2: {"name": "AC 3-Tier", "multiplier": 1.5, "baggage": 30},
    3: {"name": "AC 2-Tier", "multiplier": 2.0, "baggage": 40}
}

# only Valid promo codes for 20% discount and 500rs off
PROMO_CODES = {
    "ADG20": 0.20,      # 20% discount
    "WINTER500": 500    # Flat rs 500 discount
}