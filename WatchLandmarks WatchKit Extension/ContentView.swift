//
//  ContentView.swift
//  WatchLandmarks WatchKit Extension
//
//  Created by Cleyson Silva on 07/12/21.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        LandmarkList()
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
            .environmentObject(ModelData())
    }
}
