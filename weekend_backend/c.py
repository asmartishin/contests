#!/usr/bin/env python

import json
import sys


class Offer(object):
    def __init__(self, offer_id, market_sku, price):
        self.offer_id = offer_id
        self.market_sku = market_sku
        self.price = price

    def __eq__(self, other):
        return self.offer_id == other.offer_id

    def __lt__(self, other):
        if (self.price == other.price):
            return self.offer_id < other.offer_id
        return self.price < other.price

    def to_json(self):
        return {
            "offer_id": self.offer_id,
            "market_sku": self.market_sku,
            "price": self.price,
        }


if __name__ == "__main__":
    offers = []
    n = int(sys.stdin.readline().strip())

    for i in range(n):
        line = sys.stdin.readline().strip()
        data = json.loads(line)
        for obj in data['offers']:
            offers.append(Offer(obj['offer_id'], obj['market_sku'], obj['price']))

    offers.sort()
    result = {
        "offers": [x.to_json() for x in offers]
    }

    print(json.dumps(result))
